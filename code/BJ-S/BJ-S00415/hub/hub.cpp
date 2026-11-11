#include <bits/stdc++.h>
using namespace std;
int cid,t,n,k,x,y,ans=1e18;
vector <int> g[20];

vector <int> v;
int vis[20],vd[20];

void ltk(int u){
    vd[u]=1;
    for(int i:g[u]){
        if(vis[i]&&!vd[i]) ltk(i);
    }
}
int dis[20][20];
void getdis(int st){
    for(int i=1;i<=n;i++) dis[st][i]=1e18;
    dis[st][st]=0;
    queue <int> q;
    q.push(st);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i:g[cur]){
            if(dis[st][i]>dis[st][cur]+1){
                dis[st][i]=dis[st][cur]+1;
                q.push(i);
            }
        }
    }
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++) vd[i]=0;
    for(int i:v){
        if(!vd[i]){
            cnt++;
            ltk(i);
        }
    }
    return cnt<=2;
}
void dfs(int now,int cnt){
    if(cnt==k){
        if(!check()) return ;
        int mx=0;
        for(int i=1;i<=n;i++){
            int mn=1e18;
            for(int j:v){
                mn=min(mn,dis[i][j]);
            }
            mx=max(mx,mn);
        }
        ans=min(ans,mx);
        return ;
    }
    if(now==n+1) return ;
    dfs(now+1,cnt);
    v.push_back(now);vis[now]=1;
    dfs(now+1,cnt+1);
    v.pop_back(),vis[now]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cid>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            getdis(i);
        }
        ans=1e18;
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5


10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
