#include <bits/stdc++.h>
using namespace std;
long int c,t,n,k;
long int x[1000001];
long int u[1000001],v[1000001];
int main(){
    cin>>c>>t;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        for(int j=1;j<=n-1;j++){
            cin>>u[i]>>v[i];
        }
    }
    if(c!=0){
        freopen("migrate.in", "r", stdin);
        freopen("migrate.out", "w", stdout);}
    return 0;
}







/*long int maxn;
int G[100001][100001];
const int inf=0x3f3f3f3f;
int dis[maxn],cnt[maxn],vis[maxn];
bool spfa(int st){
    queue<int> qeueu;
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!qeueu.empty()){
        int u=qeueu.front();
        qeueu.pop();
        vis[u]=0;
        for(int i=0;i<G[u].size();i++){
            if(dis[v]>dis[u]+G[u][i].w){
                dis[v]=dis[u]+G[u][i].w;
                if(cnt[v]>=n){
                    return true;}
                if(!vis[v]){
                    qeueu.push(v);
                    vis[v]=1;}}}}
    return false;}*/
