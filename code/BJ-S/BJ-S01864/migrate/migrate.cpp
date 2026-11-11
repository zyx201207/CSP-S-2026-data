#include<bits/stdc++.h>//T3
#define int long long
using namespace std;
const int N=2e6+13;
int a[N];
int c,T;
vector<int>g[N];
int dis[N],cnt[N];
void bfs(int st){
    memset(cnt,0,sizeof(cnt));
    fill(dis,dis+1+N,1e9+13);
    cnt[st]=1;
    dis[st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }
            else if(dis[v]==dis[u]+1){
                cnt[v]+=cnt[u];
                q.push(v);
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>T;
    while(T--){
        int ans=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++){
            int j=i-1;
            while(j>=1&&a[i]-a[j]<=d){
                g[i].push_back(j);
                g[j].push_back(i);
                j--;
            }
        }
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
