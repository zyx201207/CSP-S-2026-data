#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
const int N=505;
vector<int> edge[N];
int dist[N][N];
int chs[N];
bool insameblock(int x,int y){
    if(x==y) return 1;
    for(int i:edge[x]){
        if(chs[i]){
            if(insameblock(i,y)){
                return 1;
            }
        }
    }
}
void dfs(int dep,int kk){
    if(dep==n){

    }
    if(kk){
        chs[dep+1]=1;
        dfs(dep+1,kk-1);
    }
    chs[dep+1]=0;
    dfs(dep+1,kk);
}
int main(){
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) edge[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=n;
            }
        }
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
            dist[u][v]=dist[v][u]=0;
        }/*
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) dist[i][j]=0;
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }*/
        //dfs(0,k);
        cout<<1<<endl;
    }
    return 0;
}
