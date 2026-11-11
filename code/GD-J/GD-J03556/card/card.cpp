#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],tong[3000005];
stack <int> st;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		tong[a[i]]++;
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=i; j<=n; j++)
		{
			;
		}
	}
	for(int i=1; i<=m; i++)
	{
		if(tong[i]>0)
		{
			cout << tong[i] <<' ';
		}
	}
	return 0;
}
