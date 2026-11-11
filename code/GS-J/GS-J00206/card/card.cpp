#include <bits/stdc++.h>

using namespace std;

int n,m,a[5];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<i<<' ';
		}
		return 0;
	}
	return 0;
}
