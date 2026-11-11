#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int v,c;
};
int C,n,m,d,q,a[5000010],dis[5010][5010],cnt,tt;
vector<node> dq[5000010];
void floyd(){
    memset(dis,0x3f,sizeof(dis));
    tt=dis[1][1];
    for(int u=1;u<=cnt;u++){
        dis[u][u]=0;
        for(int i=0;i<dq[u].size();i++){
            int v=dq[u][i].v,c=dq[u][i].c;
            dis[u][v]=c;
        }
    }
    for(int u=1;u<=cnt;u++){
        for(int v=1;v<=cnt;v++){
            for(int i=1;i<=cnt;i++){
                dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
            }
        }
    }
    for(int u=cnt;u>=1;u--){
        for(int v=cnt;v>=1;v--){
            for(int i=cnt;i>=1;i--){
                dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    cnt=m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k,tp;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y,w;
            cin>>x>>w;
            y=++cnt;
            dq[x].push_back({y,w});
            dq[y].push_back({x,w});
            if(j>1){
                dq[y].push_back({tp,0});
                dq[tp].push_back({y,0});
            }
            tp=y;
        }
    }
    floyd();
    /*
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            if(dis[i][j]==tt) cout<<-1<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<'\n';
    }
    */
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(a[x]+a[y]+dis[x][y])<<'\n';
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
