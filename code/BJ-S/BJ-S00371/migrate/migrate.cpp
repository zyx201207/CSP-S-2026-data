#include<bits/stdc++.h>
#define int long long
using namespace std;
const int S = 5e3+5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n,m,x[S],d[S],cnt[S];
// bool vis[S];
vector<int> a[S];
void clr(){
    for(int i = 1;i <= n;i++) a[i].clear();
}
void init(){
    memset(d,0x3f,sizeof d);
    memset(cnt,0,sizeof cnt);
    // for(int i = 0;i < S;i++){
        // cnt[i] = 1;
    // }
}
void bfs(int s){
    // int e = 1;
    d[s] = 0;
    cnt[s]++;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(),len = a[u].size();//cout << u << ' ';
        q.pop();
        for(int i = 0;i < len;i++){
            int v = a[u][i];
            if(d[v] == inf){
                q.push(v);
                d[v] = d[u] + 1;
                cnt[v] += cnt[u];
                continue;
            }
            // if(d[v] == inf)
            // q.push(v);
            if(d[v] == d[u] + 1) cnt[v] += cnt[u];
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    scanf("%lld %lld",&C,&T);
    while(T--){
        clr();
        scanf("%lld %lld",&n,&m);
        for(int i = 1;i <= n;i++){
            scanf("%lld",&x[i]);
        }
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(x[j] - x[i] <= m) {
                    a[j].push_back(i);
                    a[i].push_back(j);
                    // printf("%lld %lld\n",i,j);
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            init();
            bfs(i);//puts("");
            for(int j = 1;j <= n;j++){
                if(cnt[j] == 2) ans++;
                // cout << cnt[j] << " ";
            }
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}