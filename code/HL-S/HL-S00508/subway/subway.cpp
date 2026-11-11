#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[10010],k[10010],a[1001][1001],t[1001][1001],x[10010],y[10010];
signed main()
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
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=x[i];j<=y[i];j++)
		{
			ans+=t[i][j];
		}
		ans+=w[y[i]]+w[x[i]];
		cout<<ans<<endl;
	}
	
		 
	return 0;
}
               