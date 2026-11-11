/*
作者怎么被Q气成这样 RP++ RP++ RP++
不不不这是什么猎奇的编译错误
不不不我不写了就当是死了俩小时
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
const int K=5000,M=5000,N=500,Q=100000;//5e5 5e5 5e2 1e5
bool vis[M+10];
int m,n,q;//5e5 5e2 1e5
ll dis[M+10][M+10];//5e11
vector<pii>adj[M+10];//{5e5,1e9}
int a[N+10][K+10],t[N+10][K+10];//5e2 1e9
int k[N+10],w[M+10],x[Q+10],y[Q+10];//1e9 5e2 5e2
void Dijkstra(int aa){
    for(int i=1;i<=n;i++)vis[i]=false;
    priority_queue<pli>pq;//<5e11,5e5>
    pq.push({0,aa});
    for(int i=1;i<=n;i++)dis[aa][i]=0x7f7f7f7f;
    dis[aa][aa]=0;
    while(!pq.empty()){
        pli top=pq.top();//<5e11,5e5>
        pq.pop();
        int a=top.second;//5e5
        bool&va=vis[a];
        if(va)continue;
        va=true;
        ll da=top.first;//5e11
        for(pii i:adj[a]){
            int b=i.first;//5e5
            if(vis[b])continue;
            ll&db=dis[aa][b],nd=da+i.second;//5e11 5e11
            if(nd>=db)continue;
            db=nd;
            pq.push({db,b});
        }
    }
}
void A(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=2;j++)
            adj[a[i][j]].push_back({a[i][3-j],t[i][1]+t[i][2]});
    for(int i=1;i<=m;i++)Dijkstra(i);
    for(int i=1;i<=q;i++)cout<<w[x[i]]+dis[x[i]][y[i]]+w[y[i]]<<'\n';
}
void Floyd(){
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<k[i];j++)
            dis[a[i][j]][a[i][j+1]]=dis[a[i][j+1]][a[i][j]]=t[i][j]+t[i][j+1];
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++)cout<<dis[i][j]<<' ';
    //     cout<<'\n';
    // }
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++){
                // cout<<i<<' '<<j<<' '<<k<<' '<<dis[i][j]<<' '<<dis[i][k]+dis[k][j]<<'\n';
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                // cout<<"now:"<<dis[i][j]<<'\n';
            }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++)cout<<dis[i][j]<<' ';
    //     cout<<'\n';
    // }
    for(int i=1;i<=q;i++)cout<<w[x[i]]+dis[x[i]][y[i]]+w[y[i]]<<'\n';
}
void baoli(){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,d;//25 20 
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
    if(7<=c&&c<=11)A();
    else if(c<=6)Floyd();
    else baoli();
    return 0;
}