#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 550;
int c,T;
int x[N];
int r[N];
int l[N];
vector<int>e[N];
int dis[N];
int num[N];
void bfs(int now){
    memset(dis,-1,sizeof(dis));
    memset(num,0,sizeof(num));
    dis[now] = 0;
    num[now] = 1;
    queue<int>q;
    q.push(now);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:e[u]){
            if(dis[v]==dis[u]+1)num[v]+=num[u];
            else if(dis[v]==-1){
                dis[v] = dis[u]+1;
                num[v]+=num[u];
                q.push(v);
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        int ans = 0;
        for(int i = 1;i<=n;i++)cin>>x[i];
        for(int i = 1;i<=n;i++)e[i].clear();
        for(int i = 1;i<=n;i++){
            r[i] = upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            l[i] = lower_bound(x+1,x+n+1,x[i]-d)-x;
            for(int j = l[i];j<=r[i];j++){
                if(j!=i)e[i].push_back(j);
            }
        }
        for(int i = 1;i<=n;i++){
            bfs(i);
            for(int j = 1;j<=n;j++){
                if(num[j]==2)ans++;
            }
        }
        cout<<ans/2<<"\n";
    }


    return 0;
}