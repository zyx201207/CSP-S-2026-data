#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[106];
int b[106];
bool vis[106];
int ans=2e9;
int bfs(int x){
    queue<pair<int,pair<int,int> > > q;
    q.push({x,{0,0}});
    while (!q.empty()){
        int nx=q.front().first;
        int step=q.front().second.first;
        int f=q.front().second.second;
        q.pop();
        if (vis[nx]) return step;
        for (int i:v[nx]){
            if (i==f) continue;
            q.push({i,{step+1,nx}});
        }
    }
}
int solve(){
    int ma=0;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            ma=max(ma,bfs(i));
        }
    }
    return ma;
}
bool check(int x){
    for (int i:v[x]){
        if (vis[i]) return 1;
    }
    return 0;
}
void dfs(int x,int cnt){
    if (x>n){
        if (cnt!=k) return;
        int count=0;
        for (int i=1;i<=cnt;i++){
            if (check(i)==0) count++;
            vis[i]=1;
        }
        if (count>2){
            for (int i=1;i<=n;i++) vis[i]=0;
            return;
        }
        cout<<count<<" ";
        for (int i=1;i<=cnt;i++) cout<<b[i]<<" ";
        cout<<'\n';
        ans=min(ans,solve());
        return;
    }
    dfs(x+1,cnt);
    if (cnt<k) {
        b[++cnt]=x;
        dfs(x+1,cnt);
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        ans=2e9;
        cin>>n>>k;
        for (int i=1;i<=n;i++){
            v[i].clear();
            vis[i]=0;
            b[i]=0;
        }
        for (int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
