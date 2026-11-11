#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int a[2000005];
int dis[2000005];
int cnt[2000005];
vector<int> G[200005];
void bfs(int x){
    for(int i=1;i<=n;i++){
        dis[i]=-1;
        cnt[i]=0;
    }
    queue<int> q;
    dis[x]=0;
    cnt[x]=1;
    q.push(x);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto nx:G[x]){
            if(dis[nx]==-1){
                dis[nx]=dis[x]+1;
                cnt[nx]=cnt[x];
                q.push(nx);
                continue;
            }
            if(dis[x]+1>dis[nx]) continue;
            cnt[nx]+=cnt[x];
            if(cnt[nx]>2) cnt[nx]=3;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            G[i].clear();
        }
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]>d) continue;
            G[i].push_back(j);
            G[j].push_back(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=i;j<=n;j++) ans+=(cnt[j]==2);
        }
        cout<<ans<<"\n";
    }
}