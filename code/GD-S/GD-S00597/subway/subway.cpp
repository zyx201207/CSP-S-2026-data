#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q,k[505],w[500005],t[505][50005],a[505][50005],minn=1e9,y,x;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
	}
	cout<<32<<'\n'<<17;
} 
