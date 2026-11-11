#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,maxx = -1;
	cin >> n >> m;
	int a[n];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = n-i;j <= n;j++)
		{
			if(a[i] & a[j] >= maxx)
			{
				maxx = a[i]&a[j];
			}
		}
	}
	cout << maxx;
 } 
