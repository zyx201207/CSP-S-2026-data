#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
int e[1005][1005];
int cmp[1005],k[505],t[1005],a[1005];
int dis[1005],vis[1005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>cmp[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>t[j]>>a[j];
        }
        for(int j=1;j<=k[i];j++){
            for(int p=j+1;p<=k[i];p++){
                e[t[j]][t[p]]=a[j]+a[p];
                e[t[p]][t[j]]=a[j]+a[p];
            }
        }
    }
    //for(int i=1;i<=m;i++){
        //for(int j=i+1;j<=m;j++){
            //cout<<i<<" "<<j<<" "<<e[i][j]<<endl;
        //}
    //}
    while(q--){
        memset(dis,0x3f3f3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        int x,y;
        cin>>x>>y;
        dis[x]=0;
        q1.push({0,x});
        while(!q1.empty()){
            int u=q1.top().second,w=q1.top().first;
            q1.pop();
            if(vis[u]) continue;
            vis[u]=1;
            //cout<<u<<"&&&\n";
            for(int v=1;v<=m;v++){
                if(e[u][v]!=0 && dis[v]>w+e[u][v]){
                    dis[v]=w+e[u][v];
                    q1.push({dis[v],v});
                }
            }
        }
        cout<<dis[y]+cmp[x]+cmp[y]/*<<"***"*/<<endl;
    }
    return 0;
}
