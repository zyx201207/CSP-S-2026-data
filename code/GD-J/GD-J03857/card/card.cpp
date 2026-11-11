#include<bits/stdc++.h>
using namespace std;
int f[311111];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		f[x]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<' ';
	}
	return 0;
}
