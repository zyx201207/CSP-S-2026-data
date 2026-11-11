#include<bits/stdc++.h>
using namespace std;

int m, n, a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;// ‰»Î
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	int nmax = 0;
	for(int i=1; i<=n-m+1; i++)
	{
		for(int j=i; j<=n; j++)
		{
			if(nmax < a[i]&a[j])
			{
				nmax = a[i]&a[j];
			}
		}
	}
	cout << nmax;
	return 0;	
}
