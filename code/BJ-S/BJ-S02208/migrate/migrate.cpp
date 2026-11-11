#include <bits/stdc++.h>
using namespace std;
long long ans;
long long c,t,n,d,x[5003],dis[5003],cnt[5003],vis[5003],g[5003][5003];
void bfs(int rt){
    queue<int> q;
    q.push(rt);
    dis[rt]=0;
    while(q.size()){
        int tp=q.front();
        q.pop();
        vis[tp]=1;
        for(int i=1;i<=n;i++){
            if(g[tp][i]){
                if(!vis[i]){
                    q.push(i);
                }
                if(dis[i]>dis[tp]+1){
                    dis[i]=dis[tp]+1;
                    cnt[i]=1;
                }
                if(dis[i]==dis[tp]){
                    cnt[i]+=cnt[tp];
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        // cout<<"asdf"<<endl;
        cin>>n>>d;
        memset(g,0,sizeof(g));
        // if(n<=5000){
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]<=d){
                        g[i][j]=g[j][i]=1;
                    }
                }
                
            }
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=n;j++){
            //         cout<<g[i][j];
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            for(int i=1;i<=n;i++){
                memset(vis,0,sizeof(vis));
                memset(cnt,0,sizeof(cnt));
                memset(dis,0x3f,sizeof(dis));
                bfs(i);
                // for(int j=1;j<=n;j++){
                //     cout<<dis[j]<<' ';
                // }
                // cout<<endl;
                // for(int j=1;j<=n;j++){
                //     cout<<cnt[j]<<' ';
                // }
                // cout<<endl<<endl;
                for(int j=i+1;j<=n;j++){
                    if(cnt[j]==2){
                        ans++;
                    }
                }
            }
        cout<<ans<<endl;
        // }
    }
    return 0;
}
