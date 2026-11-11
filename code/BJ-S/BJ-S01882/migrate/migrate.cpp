#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int n,dis[N];
ll x[N],d,cnt[N],ans;
vector<int> e[N];
void bfs(int start){
    for(int i=1;i<=n;i++) cnt[i]=dis[i]=0;
    queue<int> q;
    q.push(start);
    cnt[start]=dis[start]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:e[u]){
            if(!dis[v]) q.push(v);
            if(!dis[v]) dis[v]=dis[u]+1;
            if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
        }
    }
}
void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d){
                e[i].push_back(j);
                e[j].push_back(i);
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++){
        bfs(i);
        for(int j=1;j<=n;j++){
            if(cnt[j]==2) ans++;
        }
    }
    printf("%lld\n",ans/2);
    for(int i=1;i<=n;i++) e[i].clear();
    ans=0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    scanf("%d%d",&c,&t);
    while(t--) solve();
    return 0;
}