#include <bits/stdc++.h>
using namespace std;

int arr[10000005] = {};
bool arrB[10000005] = {true};
int n, m;
int maxA = 0;
int preA;

void backtrack(int count)
{
	if(count == m)
	{
		
		if(preA > maxA)
			maxA = preA;
			
		return ;
	}
	
	for(int i = 0; i < n; i++)
	{	
		if(arrB[i])
		{
			if(preA == 0)
				preA = arr[i];
				
			arrB[i] = false;
			int temp = preA;
			preA &= arr[i];
				
			backtrack(count + 1);
			
			arrB[i] = true;
			preA = temp;
		}
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];	
		arrB[i] = true;
	}
		
    preA = arr[0];
	backtrack(0);
	
			
	cout << maxA;
	
	return 0;
}
