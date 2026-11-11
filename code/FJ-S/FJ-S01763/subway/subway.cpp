#include<bits/stdc++.h>
using namespace std;
const int N=600,M=5e5+100,D=25;
int tag[M],lines[M][D];
map<int,int> id[M];
long long w[M],t[M][D];
int head[N],nxt[N*N],to[N*N],idx[N*N],cnt=0;
long long val[N*N];
inline void add(int u,int v,long long len,int id)
{	nxt[++cnt]=head[u],to[cnt]=v,val[cnt]=len,idx[cnt]=id,head[u]=cnt;
	nxt[++cnt]=head[v],to[cnt]=u,val[cnt]=len,idx[cnt]=id,head[v]=cnt;
	return ;
}
int n;
pair<int,int> pre[N][N];
long long dis[N][N];
bool vis[N];
priority_queue<pair<long long,int> > pq;
void solve(int S)
{	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++) dis[S][i]=1e18,vis[i]=false;
	dis[S][S]=0,pre[S][S]=make_pair(0,0),pq.push(make_pair(0,S));
	while(!pq.empty())
	{ int u=pq.top().second;pq.pop();
	  if(vis[u]) continue;
	  vis[u]=true;
	  for(int i=head[u];i;i=nxt[i])
	  { int v=to[i],k1=pre[S][u].second,k2=idx[i];
	    long long len=dis[S][u]+val[i];
		if(k1!=k2) len+=t[k1][id[k1][u]]+t[k2][id[k2][v]];
	    if(dis[S][v]>len)
		  dis[S][v]=len,pre[S][v]=make_pair((k1?pre[S][u].first:k2),k2),
		  pq.push(make_pair(-dis[S][v],v));
	  }
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{ int k;cin>>k;
	  for(int j=1;j<=k;j++)
	  { int a;cin>>a;
	    long long ti;cin>>ti;
	    tag[a]++,lines[a][tag[a]]=i,t[a][tag[a]]=ti,id[a][i]=tag[a];
	  }
	}
	for(int i=1;i<=m;i++)
	  if(tag[i]>1)
	    for(int j=1;j<tag[i];j++)
	      for(int k=j+1;k<=tag[i];k++)
	        add(lines[i][j],lines[i][k],t[i][j]+t[i][k],i);
	for(int i=1;i<=n;i++) solve(i);
	while(q--)
	{ int x,y;cin>>x>>y;
	  long long ans=2e18;
	  for(int i=1;i<=tag[x];i++)
	  { int u=lines[x][i];
	    for(int j=1;j<=tag[y];j++)
	    { int v=lines[y][j],
	          k1=pre[u][v].first,k2=pre[u][v].second,
	          idx1=id[k1][u],idx2=id[k2][v];
	      long long now=dis[u][v];
	      if(k1!=x) now+=t[x][i]+t[k1][idx1];
	      if(k2!=y) now+=t[y][j]+t[v][idx2];
	      ans=min(ans,now);
		}
	  }
	  cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}