#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int cnt=0,name[30],t[30];
}e[500010];
int c,n,m,d,q,w[500010],way[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            e[a].cnt++;
            e[a].name[e[a].cnt]=i;
            e[a].t[e[a].cnt]=t;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            way[i][j]=1e18;
        }
        way[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=e[i].cnt;j++){
            for(int k=1;k<j;k++){
                int u=e[i].name[j];
                int v=e[i].name[k];
                int len=e[i].t[j]+e[i].t[k];
                way[u][v]=min(way[u][v],len);
                way[v][u]=min(way[v][u],len);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                way[i][j]=min(way[i][j],way[i][k]+way[k][j]);
            }
        }
    }
    while(q--){
        int u,v,ans=1e18;
        cin>>u>>v;
        for(int i=1;i<=e[u].cnt;i++){
            for(int j=1;j<=e[v].cnt;j++){
                ans=min(ans,e[u].t[i]+e[v].t[j]+way[e[u].name[i]][e[v].name[j]]);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
