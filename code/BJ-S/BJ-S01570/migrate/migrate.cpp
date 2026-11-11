#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,s,a[500001],sum[500001],dis[1010][1010],ans,vis[500010],tt[1010][1010];
vector<int> dq[1000010];
void floyd(){
    memset(dis,0x3f,sizeof(dis));
    for(int u=1;u<=n;u++){
        dis[u][u]=0;
        for(int i=0;i<dq[u].size();i++){
            int v=dq[u][i];
            dis[u][v]=1;
        }
    }
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            for(int i=1;i<=n;i++){
                dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
            }
        }
    }
    for(int u=n;u>=1;u--){
        for(int v=n;v>=1;v--){
            for(int i=n;i>=1;i--){
                dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
            }
        }
    }
}
void dfs(int u,int fa,int ds){
    /*
    cout<<s<<" "<<u<<" "<<ds<<" "<<dis[s][u]<<'\n';
    */
    if(ds==dis[s][u]){
        sum[u]++;
        //cout<<"*";
    }
    /*
    for(int j=1;j<=n;j++){
        cout<<sum[j]<<" ";
    }
    cout<<'\n';
    */
    if(vis[u]) return;
    vis[u]=1;
    for(int i=0;i<dq[u].size();i++){
        int v=dq[u][i];
        if(v==fa || vis[v]) continue;
        dfs(v,u,ds+1);
        vis[v]=0;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])<=d){
                    dq[i].push_back(j);
                    dq[j].push_back(i);
                }
            }
        }
        floyd();
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<'\n';
        }
        */
        for(int i=1;i<n;i++){
            //cout<<'\n'<<'\n';
            s=i;
            dfs(s,0,0);
            for(int j=1;j<=n;j++){
                //cout<<sum[j]<<" ";
                if(sum[j]==2 && tt[i][j]==0){
                    ans++;
                    tt[i][j]=tt[j][i]=1;
                }
                sum[j]=0;
                vis[j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            dq[i].clear();
            for(int j=1;j<=n;j++){
                tt[i][j]=0;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
