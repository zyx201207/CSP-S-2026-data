#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll n,d,x[N];
vector<int> g[N];
ll dist[N],cnt[N];
bool vis[N];
void dijkstra(int s){
    fill(dist+1,dist+n+1,1e9);
    fill(cnt+1,cnt+n+1,0);
    fill(vis+1,vis+n+1,false);
    dist[s]=0;
    cnt[s]=1;
    vis[s]=true;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int v:g[u]){
            if(!vis[v]){
                vis[v]=true;
                dist[v]=dist[u]+1;
                cnt[v]=cnt[u];
                que.push(v);
            }else if(dist[u]+1==dist[v]){
                cnt[v]+=cnt[u];
            }
        }
    }
    return ;
}
void solve(){
    cin >>n>>d;
    for(int i=1;i<=n;i++){
        cin >>x[i];
        g[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        dijkstra(i);
        for(int j=i;j<=n;j++){
            if(cnt[j]==2){
                ans++;
            }
        }
    }
    cout <<ans<<"\n";
    return ;
}
void sol1(){
    cin >>n>>d;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin >>x[i];
    }
    ll ans=0;
    for(int i=4;i<=n;i++){
        ans+=((x[i]-x[i-1]<=d)&(x[i]-x[i-2]<=d)&(x[i-1]-x[i-2]<=d)&(x[i-1]-x[i-3]<=d)&(x[i-2]-x[i-3]<=d)&(x[i]-x[i-3]>d));
    }
    cout <<ans<<"\n";
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >>c>>t;
    if(c==11 || c==12 || c==13 || c==14){
        while(t--){
            sol1();
        }
        return 0;
    }
    while(t--){
        solve();
    }
    return 0;
}
