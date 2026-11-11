#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q,w[1000000],k[1000000],a[501][1000000],t[501][10000],x[100000],y[100000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		if(k[i]==1)
		{
			cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]];
		}
	}
}

