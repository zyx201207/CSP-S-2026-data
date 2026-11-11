#include <bits/stdc++.h>
#define lol long long
using namespace std;
const lol inf=1e17;
int C,N,M,D,Q;
lol w[500050];
lol dis[520][520];//dis between stops
struct Edge{int to;lol w;};
vector <Edge> E[500050];//every vertex's connected stops

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin>>C>>N>>M>>D>>Q;
  for(int i=1;i<=M;i++){cin>>w[i];}
  for(int u=1;u<=N;u++){
    int K;cin>>K;
    for(int i=1;i<=K;i++){
      int v;lol t;cin>>v>>t;
      E[v].emplace_back((Edge){u,t});
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(i==j) continue;
      dis[i][j]=inf;
    }
  }
  for(int i=1;i<=M;i++){
    for(Edge &a:E[i]){
      int u=a.to;
      lol w1=a.w;
      for(Edge &b:E[i]){
        int v=b.to;
        lol w2=b.w;
        dis[u][v]=min(dis[u][v],w1+w2);
      }
    }
  }
  for(int k=1;k<=N;k++){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
      }
    }
  }
  while(Q--){
    int x,y;
    cin>>x>>y;
    lol ans=inf;
    for(Edge &a:E[x]){
      int u=a.to;
      lol w1=a.w;
      for(Edge &b:E[y]){
        int v=b.to;
        lol w2=b.w;
        ans=min(w1+w2+dis[u][v],ans);
      }
    }
    cout<<ans+w[x]+w[y]<<'\n';
  }
	return 0;
}

/*
Sample Input 1
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

Sample Input 2
0 3 7 20 2 
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3

*/