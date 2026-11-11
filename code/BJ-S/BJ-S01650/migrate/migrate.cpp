#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int t;
long long a[200005];
vector<int> adj[200005];
bool vis[200005];
struct node{
    int u;
    int v;
};
node e[2000005];
node dag[2000005];
bool vis1[200005];
int in[200005];
int dp[200005];
vector<int> adj1[200005];
int d[200005];
void bfs(int x){
    queue<int> q;
    q.push(x);
    d[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(int v:adj[u]){
            if(d[u]+1<d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void dfs1(int u){
    if(vis1[u]){
        return;
    }
    vis1[u]=1;
    for(int v:adj[u]){
        dfs1(v);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n;
        int D;
        cin>>n>>D;
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(abs(a[i]-a[j])<=D){
                        adj[i].push_back(j);
                        e[++cnt]={i,j};
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj1[j].clear();
                vis[j]=0;
                in[j]=0;
                dp[j]=0;
                d[j]=1e9;
            }
//            cout<<"now:"<<i<<"\n";
            bfs(i);
//            for(int j=1;j<=n;j++){
//                cout<<d[j]<<" ";
//            }
//            cout<<"\n";
            queue<int> q;
            for(int j=1;j<=cnt;j++){
                int u=e[j].u;
                int v=e[j].v;
                if(d[v]==d[u]+1 and vis[u] and vis[v]){
//                    cout<<u<<" "<<v<<"\n";
                    adj1[u].push_back(v);
                    in[v]++;
                }
            }
//            cout<<"\n";
            q.push(i);
            dp[i]=1;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:adj1[u]){
//                    cout<<u<<" "<<v<<" "<<dp[u]<<" "<<dp[v]<<"\n";
                    dp[v]+=dp[u];
                    in[v]--;
                    if(in[v]==0){
                        q.push(v);
                    }
                }
            }
            for(int j=i+1;j<=n;j++){
//                cout<<dp[j]<<" ";
                if(dp[j]==2){
                    ans++;
                }
            }
//            cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
