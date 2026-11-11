#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<numeric>
#include<utility>
#include<vector>
#include<set>
#include<queue>
#define INF 0x3F3F3F3F3F3F3F3Fll
using namespace std;
struct node {
  int next,v,w;
};
int cid,n,m,d,q,x,y,num_edge;
int head[100005],w[500005],vis[100005];
long long dis[4005][4005];
node edge[100005];
void add(int u,int v,int w) {
  num_edge++;
  edge[num_edge]=(node){head[u],v,w};
  head[u]=num_edge;
}
void dijkstra(int s) {
  for(int i=1;i<=m+n;i++)
    if(i!=s)
      dis[s][i]=INF;
  memset(vis,0,sizeof(int)*(m+n+1));
  priority_queue<pair<long long,int> > q;
  q.push(make_pair(-dis[s][s],s));
  while(q.size()) {
    int u=q.top().second;
    q.pop();
    if(vis[u])
      continue;
    vis[u]=true;
    for(int i=head[u];i>0;i=edge[i].next) {
      int v=edge[i].v;
      if(dis[s][u]+edge[i].w<dis[s][v]) {
        dis[s][v]=dis[s][u]+edge[i].w;
        q.push(make_pair(-dis[s][v],v));
	  }
	}
  }
}
void solve1() {
  for(int i=1,k,sta,tim;i<=n;i++) {
    cin>>k;
    for(int j=1;j<=k;j++) {
      cin>>sta>>tim;
      add(sta,i+m,tim); add(i+m,sta,tim);
	}
  }
  for(int i=1;i<=m;i++)
    dijkstra(i);
  while(q--) {
    cin>>x>>y;
    cout<<w[x]+w[y]+dis[x][y]<<'\n';
  }
}
long long bfs(int s,int t) {
  static long long dis[100005];
  dis[s]=0;
  memset(vis,0,sizeof(int)*(m+n+1));
  queue<int> q;
  q.push(s);
  vis[s]=true;
  while(q.size()) {
    int u=q.front();
    for(int i=head[u];i>0;i=edge[i].next) {
      int v=edge[i].v;
      if(vis[v])
        continue;
      dis[v]=dis[u]+edge[i].w;
      q.push(v);
      vis[v]=true;
	}
	q.pop();
  }
  return dis[t];
}
void solve2() {
  for(int i=1,k,sta,tim;i<=n;i++) {
    cin>>k;
    for(int j=1;j<=k;j++) {
      cin>>sta>>tim;
      add(sta,i+m,tim); add(i+m,sta,tim);
	}
  }
  while(q--) {
    cin>>x>>y;
    cout<<w[x]+w[y]+bfs(x,y)<<'\n';
  }
}
void solve3() {
  if(n<=1000) {
    solve1();
    return;
  }
  static int t[2][500005];
  for(int i=0,k,sta,tim;i<n;i++) {
    cin>>k;
    for(int j=0;j<k;j++) {
      cin>>sta>>tim;
      t[i][sta]=tim;
	}
  }
  long long minx=INF;
  for(int i=1;i<=n;i++)
    if(t[0][i] && t[1][i])
      minx=min(minx,1ll*t[0][i]+t[1][i]);
  while(q--) {
    cin>>x>>y;
    long long ans=INF;
    if(t[0][x]) {
      if(t[0][y])
        ans=min(ans,1ll*t[0][x]+t[0][y]);
      if(t[1][y] && minx<INF)
        ans=min(ans,minx+t[0][x]+t[1][y]);
	}
	if(t[1][x]) {
	  if(t[0][y] && minx<INF)
	    ans=min(ans,minx+t[1][x]+t[0][y]);
	  if(t[1][y])
	    ans=min(ans,1ll*t[1][x]+t[1][y]);
	}
	ans=ans+w[x]+w[y];
	cout<<ans<<'\n';
  }
}
int main() {
  freopen("subway.in","r",stdin);
  freopen("subway.out","w+",stdout);
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin>>cid>>n>>m>>d>>q;
  for(int i=1;i<=m;i++)
    cin>>w[i];
  if(cid>=12 && cid<20)
    solve2();
  else
  if(cid<12)
    solve1();
  else
    solve3();
}

