#include <iostream>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------------------------------------

//**********make changes here******************

vector <int> H;
int N;

//---------------------------------------------------------------------------------------------------------

void heap_init();
void swap(int a, int b);
void maxHeapify(int idx);
void insert(int x);
void printMax();
void popMax();

void swap(int a, int b)
{
	int temp = H[a];
	H[a] = H[b];
	H[b] = temp;
}

void maxHeapify(int idx)
{
	int leftChild = 2 * idx, rightChild = 2 * idx + 1, largest = idx;

	if (leftChild <= N && H[leftChild] > H[largest])
		largest = leftChild;

	if (rightChild <= N && H[rightChild] > H[largest])
		largest = rightChild;

	if (largest != idx)
	{
		swap(idx, largest);
		maxHeapify(largest);
	}
}

void buildHeap()
{
	for (int i = N/2; i > 0; i--)
		maxHeapify(i);
}

void insert(int x)
{
	H[++N] = x;

	if (N > 1)
	{
		int parent = N / 2, child = N;

		while (H[child] > H[parent] && parent > 0)
		{
			swap(child, parent);
			child = parent;
			parent /= 2;
		}
	}
}

void printMax()
{
	N == 0 ? cout << "Heap is empty!\n" : cout << H[1] << "\n";
}

void popMax()
{
	if (N == 0)
	{
		cout << "Heap is empty!\n";
		return;
	}

	if (N > 1)
	{
		swap(1, N);
		N--;
		maxHeapify(1);
	}

	else
		N--;
}

void increaseKey(int i, int val)
{
	if (val <= H[i])
	{
		cout << "val is less than or equal to existing value\n";
		return;
	}

	H[i] = val;

	while (i/2 >= 1 && H[i] > H[i/2])
	{
		swap(i, i/2);
		i /= 2;
	}
}

void decreaseKey(int i, int val)
{
	if (val >= H[i])
	{
		cout << "val is greater than or equal to existing value\n";
		return;
	}

	H[i] = val;
	maxHeapify(i);
}

int main()
{
    cout << "Enter number of elements\n";
    cin >> N;
    
    cout << "Enter elements\n";
    int x;
    
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        H.push_back(x);
    }
    
	buildHeap();
	cout << "Printing current max\n";
	printMax();

    cout << "Popping max element\n";
	popMax();
	cout << "Printing current max\n";
	printMax();

    cout << "Entering 100 into heap\n";

	insert(100);
	cout << "Printing current max\n";
	printMax();	

	return 0;
}