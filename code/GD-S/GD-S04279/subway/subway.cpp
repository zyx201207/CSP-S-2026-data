#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][500005],t[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][y];
	}
	return 0;
}

