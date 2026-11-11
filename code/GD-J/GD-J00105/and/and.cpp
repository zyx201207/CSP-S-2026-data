#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	int mn = INT_MAX;
	for(int i = 1;i<=m;i++)
	{
		int mx = 0,p;
		for(int j = 0;j<n;j++)
		{
			if(a[j] > mx)
			{
				mx = a[j];
				p = j;
			}
		}
		a[p] = -1;
		mn = min(mn,mx);
	}
	cout << mn;
	return 0;
}
