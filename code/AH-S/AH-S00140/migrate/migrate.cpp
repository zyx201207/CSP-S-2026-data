#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int C,n,d,x[N];
vector<int> g[N];
int dis[N];
bitset<N> vis;
int ans=0;
void bfs(int st){
    queue<int> q;
    q.push(st),dis[st]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:g[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
int cnt[N];
void get24(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[j]=1e18,vis[j]=0,cnt[j]=0;
        bfs(i);
        //for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';cout<<endl;
        int r=i,l=1;
        for(r=i-1;r>=1;r--){
            if(cnt[r]>=2) break;
        }
        if(cnt[r]==2){
            for(l=r-1;l>=1;l--){
                if(cnt[l]!=2) break;
            }l++;
            ans+=(r-l+1);
        }
        for(l=i+1;l<=n;l++)
            if(cnt[l]>=2) break;
        if(cnt[l]==2){
            for(int r=l+1;r<=n;r++){
                if(cnt[r]!=2) break;
            }r--;
            ans+=(r-l+1);
        }
    }
}
int Mind[N];
void get8(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[j]=1e18,vis[j]=0,cnt[j]=0,Mind[j]=1e18;
        bfs(i);
        for(int j=1;j<=n;j++){
            cout<<dis[j]<<' ';
            if(dis[j]>=1e18) continue;
            if(dis[j]<Mind[j]) cnt[j]=1,Mind[j]=dis[j];
            else if(dis[j]==Mind[j]) cnt[j]++;
        }cout<<endl;
    }
    for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
    for(int i=1;i<=n;i++) if(cnt[i]==2) ans++;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            if(u==v) continue;
            if(abs(x[u]-x[v])<=d) g[u].push_back(v),g[v].push_back(u);
        }
    }
    get8();
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;
    cin>>C>>T;
    while(T--) solve();
    return 0;
}
