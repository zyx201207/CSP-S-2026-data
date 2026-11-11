#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#define int long long
using namespace std;
//subway
const int N = 600;
//station
const int M = 5e5+10;
const int NM = N+M;
int c,n,m,d,q;
int edge[N][N];
// to(subway) weight
vector<pair<int,int>> edge1[M];
int w[M];
int map[N][N];
bool vis[N];
void dijkstra(int from){
  map[from][from]=0;
  // dis,p
  priority_queue<pair<int,int>> que;
  que.push({0,from});
  while(!que.empty()){
    int p = que.top().second;
    que.pop();
    if(vis[p])continue;
    vis[p]=true;
    for(int i = 1;i<=n;i++){
      if(edge[p][i]==-1)continue;
      int weight = edge[p][i];
      if(map[from][p]+weight<map[from][i]||map[from][i]==-1){
	map[from][i]=map[from][p]+weight;
	que.push({-map[from][i],i});
      }
    }
  }
  memset(vis,false,sizeof(vis));
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  memset(map,-1,sizeof(map));
  memset(edge,-1,sizeof(edge));
  cin>>c>>n>>m>>d>>q;
  for(int i = 1;i<=m;i++){
    cin>>w[i];
  }
  for(int i = 1;i<=n;i++){
    int k;
    cin>>k;
    for(int j = 1;j<=k;j++){
      int a,t;
      cin>>a>>t;
      edge1[a].push_back({i,t});
    }
  }
  for(int p = 1;p<=m;p++){
    for(int i = 0;i<edge1[p].size();i++){
      for(int j = i+1;j<edge1[p].size();j++){
	int wf = edge1[p][i].second;
	int ws = edge1[p][j].second;
	int f = edge1[p][i].first;
	int s = edge1[p][j].first;	
	if(wf+ws<edge[f][s]||edge[f][s]==-1){
	  edge[f][s] = wf+ws;
	  edge[s][f] = wf+ws;
	}	
      }
    }
  }
  for(int i = 1;i<=q;i++){
    int u,v;
    cin>>u>>v;
    int ans = -1;
    for(auto s1:edge1[u]){
      for(auto s2:edge1[v]){
	int a = s1.first;
	int b = s2.first;
	if(map[a][b]==-1&&map[b][a]==-1)dijkstra(a);
	int ans1 = max(map[a][b],map[b][a])+w[u]+w[v]+s1.second+s2.second;
	if(ans>ans1||ans==-1)
	  ans = ans1;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
