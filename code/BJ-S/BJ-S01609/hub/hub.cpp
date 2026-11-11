#include<bits/stdc++.h>
using namespace std;
vector<long long> a[1000010];
bool vis[1000010],color[1000010];
long long n,k,dis[1000010],mn=1e18;
void dfs2(long long x){
    color[x]=true;
    for(long long i=0;i<a[x].size();i++){
        if(vis[a[x][i]]&&!color[a[x][i]]){
            dfs2(a[x][i]);
        }
    }
    return;
}
queue<long long> q;
void dfs(long long x,long long k){
    if(x>n&&k>0){
        return;
    }
    if(k==0){
        memset(color,0,sizeof(color));
        long long cnt=0;
        for(long long i=1;i<=n;i++){
            if(vis[i]&&!color[i]){
                cnt++;
                if(cnt>2){
                    return;
                }
                dfs2(i);
            }
        }
        for(long long i=1;i<=n;i++){
            dis[i]=-1;
        }
        for(long long i=1;i<=n;i++){
            if(vis[i]){
                dis[i]=0;
                q.push(i);
            }
        }
        long long mx=0;
        while(!q.empty()){
            long long w=q.front();
            q.pop();
            mx=max(mx,dis[w]);
            for(long long i=0;i<a[w].size();i++){
                if(dis[a[w][i]]==-1){
                    dis[a[w][i]]=dis[w]+1;
                    q.push(a[w][i]);
                }
            }
        }
        mn=min(mn,mx);
        return;
    }
    vis[x]=true;
    dfs(x+1,k-1);
    vis[x]=false;
    dfs(x+1,k);
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--){
        mn=1e18;
        cin>>n>>k;
        for(long long i=1;i<=n;i++){
            a[i].clear();
        }
        for(long long i=1;i<n;i++){
            long long u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1,k);
        cout<<mn<<"\n";
    }
    return 0;
}

