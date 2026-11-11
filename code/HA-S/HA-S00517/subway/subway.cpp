#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],k[505],minn=LONG_LONG_MAX;
int a[505][500005],t[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
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
		minn=min(minn,t[i][1]+(long long)t[i][2]);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+minn<<"\n";
	}
	return 0;
}
