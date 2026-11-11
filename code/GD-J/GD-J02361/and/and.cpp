#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[20005];
int maxnn;

int main()
{
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	
	cin >> n >> m;	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			maxnn = max(a[i] & a[j], maxnn);
		}
	}
	
	cout << maxnn;
	
	return 0;
}
