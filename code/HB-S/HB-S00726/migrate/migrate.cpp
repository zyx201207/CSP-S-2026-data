#include <bits/stdc++.h>
#define lol long long
using namespace std;
const int inf=1e8;
int C,T;
int N;lol D;
int res=0;
lol x[5200];
int L[5200],R[5200];
int dis[5200];
int cnt[5200];
int MaxD;

struct Edge{int pre,to;}E[25000050];
int head[5200],num;

struct Node{
  int u,d;
  bool operator <(const Node &oth)const &{
    return d>oth.d;
  }
};
priority_queue <Node> PQ;
queue <int> qu;

void get_dis(int);
void dfs(int,int,int);

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin>>C>>T;
  while(T--){
    res=0;
    cin>>N>>D;
    for(int i=1;i<=N;i++){cin>>x[i];}
    for(int i=1;i<=N;i++){
      L[i]=lower_bound(x+1,x+1+N,x[i]-D)-x;
      R[i]=upper_bound(x+1,x+1+N,x[i]+D)-x-1;
    }
    for(int i=1;i<=N;i++){
      get_dis(i);
      for(int j=1;j<=N;j++){
        dfs(i,j,0);
      }
      for(int j=1;j<=N;j++){
        if(cnt[j]==2)res++;
        cnt[j]=0;
      }
    }
    cout<<(res>>1)<<'\n';
  }
	return 0;
}

void adde(int u,int v){
  E[++num]={head[u],v};head[u]=num;
}

void get_dis(int S){
  for(int i=1;i<=N;i++){dis[i]=inf;}
  dis[S]=0;
  PQ.push({S,0});
  while(!PQ.empty()){
    Node now=PQ.top();PQ.pop();
    int u=now.u,d=now.d;
    if(d>dis[u])continue;
    for(int v=L[u];v<=R[u];v++){
      if(dis[v]>dis[u]+1){
        dis[v]=dis[u]+1;
        PQ.push({v,dis[v]});
      }
    }
  }
  for(int i=1;i<=N;i++){MaxD=max(MaxD,dis[i]);}
}

void dfs(int u,int v,int d){
  if(dis[v]==inf) return ;
  if(d>dis[v]) return ;
  if(u==v){cnt[v]++;return ;}
  for(int i=L[u];i<=R[u];i++){
    dfs(i,v,d+1);
  }
}


/*
Sample Input 1
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

Sample Input 2
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

My Input 1
0 1
4 6
1 3 5 7 9 11 13 15 17 19 

My Input 2
0 1
4 10
1 4 7 11 

My Input 3
0 1
5 
1 5 9 13 18
*/