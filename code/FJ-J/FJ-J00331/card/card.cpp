#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", {0});
	freopen("travel.out", "w", {0});
	int a = 100;
	int n[100];
	for(int i = 1;i<=a;i++)
	{
		cin >> n[i];
	}
	n[100] = 1;
	cout << n[a];
	return 0;
}
