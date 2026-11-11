#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=505,M=5e5+5,D=25;
struct node{
    int id,t;
    //连接的线路
};
vector<node> g[M];//g[a].size()<=20(d)
// g[i] 站台i 经过站台i的线路j以及i->j的时间t
int w[M];
int dis[N];
void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    queue<int>q;
    while(!q.empty())q.pop();
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int p=0;p<g[now].size();p++){
            node x=g[now][p];
            int id=x.id,t=x.t;
            // cout<<now<<' '<<id<<' '<<t<<'\n';
            for(int i=1;i<=m;i++){
                if(now==i)continue;
                for(int j=0;j<g[i].size();j++){
                    int k=g[i][j].id;
                    if(k==id){
                        if(dis[i]>dis[now]+t+g[i][j].t){
                            dis[i]=dis[now]+t+g[i][j].t;
                            // cout<<now<<' '<<id<<' '<<g[i][j].t<<' ';
                            // cout<<i<<' '<<dis[i]<<'\n';
                            q.push(i);
                        }
                    }
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;cin>>a>>t;
            node add={i,t};
            g[a].push_back(add);
        }
    }
    // for(int i=1;i<=m;i++){
    //     cout<<i<<'\n';
    //     for(int j=0;j<g[i].size();j++){
    //         node x=g[i][j];
    //         cout<<x.id<<' '<<x.t<<'\n';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int s,t;cin>>s>>t;
        bfs(s);
        // for(int i=1;i<=m;i++)cout<<dis[i]<<' ';cout<<'\n';
        cout<<dis[t]+w[s]+w[t]<<'\n';
    }
    return 0;
}