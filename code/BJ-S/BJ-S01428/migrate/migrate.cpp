#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans=0;
long long d;
long long x[5005];
int cnt[5005][5005],sum[5005][5005],vis[5005][5005];
vector<int> e[5005];
void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x][x]=1;
    sum[x][x]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<e[u].size();i++){
            if(vis[x][e[u][i]]){
                if(cnt[x][e[u][i]]==cnt[x][u]+1) sum[x][e[u][i]]++;
                continue;
            }
            cnt[x][e[u][i]]=cnt[x][u]+1;
            sum[x][e[u][i]]=sum[x][u];
            vis[x][e[u][i]]=1;
            q.push(e[u][i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            e[i].clear();
        }
        if(c<=10){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cnt[i][j]=0,sum[i][j]=0,vis[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]>d) break;
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
            for(int i=1;i<=n;i++){
                bfs(i);
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(sum[i][j]==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
