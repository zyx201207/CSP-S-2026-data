#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 10;
const int N = 310;
int c,n,m,d,q;
struct Node{
    int id,val;
}a[MAXN][25];
int val[MAXN];
int cnt[MAXN];
int dis[N][N];
void floyd(){
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int name = 1;name <= m;name++){
        for(int i = 1;i <= cnt[name];i++){
            for(int j = i + 1;j <= cnt[name];j++){
                Node u = a[name][i],v = a[name][j];
                dis[u.id][v.id] = dis[v.id][u.id] = min(dis[u.id][v.id],u.val + v.val);
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> val[i];
    for(int i = 1,k;i <= n;i++){
        cin >> k;
        for(int j = 1,id,t;j <= k;j++){
            cin >> id >> t;
            a[id][++cnt[id]] = {i,t};
        }
    }
    floyd();
    while(q--){
        int u,v;
        cin >> u >> v;
        int minn = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1;i <= cnt[u];i++){
            for(int j = 1;j <= cnt[v];j++){
                minn = min(minn,a[u][i].val + a[v][j].val + dis[a[u][i].id][a[v][j].id]);
            }
        }
        cout << minn + val[u] + val[v] << '\n';
    }
    return 0;
}
