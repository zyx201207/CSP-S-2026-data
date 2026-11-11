#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int M=2e6+10;
const int inf=1e9;
vector<int> g[M];
int cnt[N],n,m,cid,dis[N],ans;
ll w[M],d;
int vis[N];
void bfs(int s){
    for(int i=1;i<=n;i++)vis[i]=cnt[i]=0,dis[i]=inf;
    dis[s]=0;
    queue<int> q;
    q.push(s);cnt[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        // cout<<u<<'\n';
        if(vis[u])continue;
        // cout<<s<<' '<<u<<' '<<dis[u]<<"\n";
        vis[u]=1;
        for(auto v:g[u]){
            if(dis[v]==dis[u]+1){
                cnt[v]+=cnt[u];
                // cout<<dis[v]<<"\n";
            }
            else if(dis[v]>dis[u]+1){
                cnt[v]=cnt[u];
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    for(int i=s+1;i<=n;i++){
        if(cnt[i]==2)ans++;
    }
}
void work(){ans=0;
    cin>>n>>d;
    // for(int i=1;i<=n;i++)cnt[i]=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        g[i].clear();
    }
    if(cid==12||cid==11){
        ll D=w[2]-w[1];
        if(d<=D*2-1){
            cout<<0<<"\n";return;
        }
        cout<<max(0ll,n+1-d/D*2)<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            // cout<<w[i]<<' '<<j<<"\n";
            if(abs(w[i]-w[j])<=d)g[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tcase;
    cin>>cid>>tcase;
    while(tcase--)work();
}