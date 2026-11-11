#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int W[500010],t[510][510];
vector<int>t1[500010],t2[510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			t[i][j]=-1;
	for(int i=1;i<=n;i++)t[i][i]=0;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		while(k--)
		{
			int v,w;cin>>v>>w;
			t2[i].pb(v);t2[i].pb(w);
			t1[v].pb(i);t1[v].pb(w);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<t2[i].size();j+=2)
			for(int u=t2[i][j],k=0;k<t1[u].size();k+=2)
			{
				int v=t1[u][k],w1=t2[i][j+1],w2=t1[u][k+1];
				if(t[i][v]==-1)t[i][v]=w1+w2;
				else t[i][v]=min(t[i][v],w1+w2);
			}
	for(int k=1;k<=n;k++)
		for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
			{
				if(t[u][k]==-1||t[k][v]==-1)continue;
				if(t[u][v]==-1)t[u][v]=t[u][k]+t[k][v];
				else t[u][v]=min(t[u][v],t[u][k]+t[k][v]);
			}
	while(q--)
	{
		int x,y;cin>>x>>y;
		int ans=LONG_LONG_MAX;
		for(int i=0;i<t1[x].size();i+=2)
			for(int j=0;j<t1[y].size();j+=2)
			{
				int u=t1[x][i],w1=t1[x][i+1],v=t1[y][j],w2=t1[y][j+1];
				ans=min(ans,w1+t[u][v]+w2);
			}
		cout<<ans+W[x]+W[y]<<endl;
	}
	return 0;
}
