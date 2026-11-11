#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
int c,T;
int n,k;
int ans;
bool vis[N],v[N];
bool vi[N];
vector<int> g[N];
inline void clean(int x){
    queue<int> q;
    memset(vi,0,sizeof(vi));
    q.push(x);
    vi[x]=true;
    while(!q.empty()){
        int u=q.front(); q.pop();
        v[u]=false;
        for(auto i:g[u]){
            if(v[i] && !vi[i]){q.push(i);vi[i]=true;}
        }
    }
}
inline bool check(){
    for(int i=1;i<=n;i++) v[i]=vis[i];
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i]){
            cnt++;
            clean(i);
        }
        if(cnt>2) return false;
    }
    return true;
}
inline int bfs(int x){
    queue<pair<int,int>> q;
    memset(vi,0,sizeof(vi));
    q.push({x,0});
    vi[x]=true;
    while(!q.empty()){
        auto u=q.front(); q.pop();
        if(vis[u.first]==true) return u.second;
        for(auto i:g[u.first]){
            if(v[i] && !vi[i]){q.push({i,u.second+1});vi[i]=true;}
        }
    }
}
inline int make_ans(){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=max(sum,bfs(i));
    }
    return sum;
}
inline void dfs(int x,int k_){
    if(x>n && k_!=0) return;
    if(k_==0){
        if(check()) ans=min(ans,make_ans());
        return;
    }
    if(n-x+1==k_){
        for(int i=x;i<=n;i++) vis[i]=true;
        if(check()) ans=min(ans,make_ans());
        for(int i=x;i<=n;i++) vis[i]=false;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(x+1,k_-1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        ans=0x3f3f3f3f;
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,k);
        cout<<ans<<endl;
    }
    return 0;
}