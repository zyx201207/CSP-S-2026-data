#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[125251],dis[501][501];
vector<int> e[125251];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
	cin>>w[i];
	e[i].push_back(0);
}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int b,c;
			cin>>b>>c;
			e[b].push_back(i);
			e[b][0]++;
			e[b].push_back(c);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dis[i][j]=1e17;
	for(int i=1;i<=n;i++)
	dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=e[i][0];j++)
		for(int k=j+1;k<=e[i][0];k++)
		{
			dis[e[i][j*2-1]][e[i][k*2-1]]=e[i][j*2]+e[i][k*2];
			dis[e[i][k*2-1]][e[i][j*2-1]]=e[i][j*2]+e[i][k*2];
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++)
	{
		int b,c,ans=1e17;
		cin>>b>>c;
		for(int i=1;i<=e[b][0];i++)
		for(int j=1;j<=e[c][0];j++)
		{
			int x=dis[e[b][i*2-1]][e[c][j*2-1]];
			if(x<1e17)
		ans=min(ans,e[b][i*2]+e[c][j*2]+x);
	}
		cout<<ans+w[b]+w[c]<<endl;
	}
	return 0;
 } 
