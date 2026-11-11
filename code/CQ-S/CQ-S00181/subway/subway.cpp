#include<bits/stdc++.h>//注意开不开long long
#include<vector>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,D,q,w[N],a[N],len,k[N],d[N],vis[N],tt[505][1005],xian[N],vs[N],dian[505][1005],vss[N];
vector<pair<int,int> > t[N];
vector<pair<int,int> > e[N];
vector<int> idx[N];
void solve(int st,int en)
{
	for(int i=1;i<=len;i++) d[i]=1e18,vis[i]=0,vs[i]=vss[i]=0;
	for(auto g:idx[en]) vs[g]=1;
	priority_queue<pair<int,int> > q;
	for(auto g:idx[st]) 
		q.push({0,g}),d[g]=0,vss[g]=1;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		
		for(auto G:t[u])
		{
			int g=G.first,ww=G.second;
			int vv=0;
			if(vss[u]) vv+=dian[xian[u]][g];
			if(vs[g])
			{
				if(d[g]>d[u]+ww+dian[xian[u]][g]+vv) d[g]=d[u]+ww+dian[xian[u]][g]+vv,q.push({-d[g],g});
			}
			else if(d[g]>d[u]+ww+vv) {d[g]=d[u]+ww+vv,q.push({-d[g],g});}
		}
	}
	int minn=1e18;
	for(auto g:idx[en]) minn=min(minn,d[g]);
	cout<<minn+w[st]+w[en]<<"\n";
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) 
		{
			int T,aj;cin>>aj>>tt[i][j];T=tt[i][j];
			e[aj].push_back({T,len+1});
			len++,xian[len]=i,dian[i][len]=tt[i][j];
			idx[aj].push_back(len);
			if(j!=1) t[len].push_back({len-1,0}),t[len-1].push_back({len,0});
		}
	}
	for(int i=1;i<=m;i++)
		for(auto G:e[i])
			for(auto GG:e[i])
			{
				if(G.second==GG.second) continue;
				t[G.second].push_back({GG.second,G.first+GG.first});
			}
	while(q--)
	{
		int x,y;cin>>x>>y;
		solve(x,y);
	}
	return 0;
}

