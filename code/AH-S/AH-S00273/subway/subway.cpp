#include<bits/stdc++.h>
using namespace std;
int kt[500010];
struct edge{
  int v;
  int w;
};
vector<edge> a[510];
int dist[500510];
int flag[500510];
void dijkstra(int s){
  memset(dist,0x3f,sizeof(dist));
  memset(flag,0,sizeof(flag));
  queue<edge>q;
  q.push({0,s});
  dist[s]=0;
  while(!q.empty()){
    edge it=q.front();
    q.pop();
    int id=it.v;
    flag[id]=1;
    for(auto nit:a[id]){
      int nd=nit.w,nid=nit.v;
      if(flag[nid]==1&&dist[nid]+nd<dist[id]){
        dist[id]=dist[nid]+nd;
      }
      if(flag[nid]==0)q.push({dist[nid],nid});
    }
  }
}
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int c,n,m,d,q;
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++){
    cin>>kt[i];
  }
  for(int i=1;i<=n;i++){
    int J,ls1,ls2;
    cin>>J;
    for(int j=1;j<=J;j++){
	  cin>>ls1>>ls2;
	  a[i].push_back({ls1+500,ls2});
      a[ls1+500].push_back({i,ls2});
	}
  }
  
  while(q--){
    int s,e;
    cin>>s>>e;
    dijkstra(s+500);
    cout<<dist[e+500]+kt[s]+kt[e]<<"\n";
  }
  return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
 
