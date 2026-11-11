#include <bits/stdc++.h>
#define lol long long
using namespace std;
const int inf=1e8;
int C,T;
int N,K;
int k;
int num;
int res;
struct Edge{int pre,to;}E[2000050];
int head[1000050],cnt;
int dis[120][120];

bool build[1000050];

void adde(int ,int );
void dfs(int);
void check(int,int);

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin>>C>>T;
  while(T--){
    cin>>N>>K;
    cnt=0;res=inf;
    for(int i=1;i<=N;i++){head[i]=0;}
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        if(i==j) continue;
        dis[i][j]=inf;
      }
    }
    for(int i=1;i<N;i++){
      int u,v;cin>>u>>v;
      dis[u][v]=dis[v][u]=1;
      adde(u,v);adde(v,u);
    }
    
    for(int p=1;p<=N;p++){
      for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
          dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
        }
      }
    }
    dfs(1);
    cout<<res<<'\n';
  }
	return 0;
}

void dfs(int idx){
  if(k>K){return ;}
  if(idx>N){
    if(k==K){
      int R=0;
      for(int i=1;i<=N;i++){
        if(build[i]){
          for(int j=1;j<=N;j++){
            if(build[j]){R=max(R,dis[i][j]);}
          }
        }
      }
      res=min(R,res);
    }
    return ;
  }
  dfs(idx+1);
  build[idx]=true;
  num=0;check(1,0);k++;
  if(num<=2){dfs(idx+1);}
  build[idx]=false;k--;
}

void adde(int u,int v){
  E[++cnt]={head[u],v};head[u]=cnt;
}

void check(int u,int fa){
  if(build[u]&&(!build[fa])) {num++;}

  for(int i=head[u];i;i=E[i].pre){
    int v=E[i].to;
    if(v==fa) continue;
    check(v,u);
  }
  return ;
}
/*
Sample Input 1
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


Sample Input 1_1
0 1
5 2
1 2
2 3
3 4
4 5

*/