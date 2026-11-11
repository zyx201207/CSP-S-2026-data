#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x = 1,s = 0;
    char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') x = -1;
    for (;isdigit(c);c = getchar()) s = s * 10 + c - '0';
    return x * s;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2e6 + 5;
int c,t,n;
ll d,x[N],dis[N],sum[N],ans,vis[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(sum,0,sizeof(sum));
    dis[s] = 0;
    sum[s] = 1;
    q.push({0,s});
    while (!q.empty()){
        int u = q.top().se;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 1;i <= n;++i)
            if (abs(x[u] - x[i]) <= d){
                if (dis[i] > dis[u] + 1){
                    dis[i] = dis[u] + 1;
                    q.push({dis[i],i});
                    sum[i] = sum[u];
                }else if (dis[i] == dis[u] + 1){
                    sum[i] += sum[u];
                    sum[i] = min(sum[i],1ll * 10);
                }
            }
    }
}
void subtask1(){
    while (t--){
        ans = 0;
        cin >> n >> d;
        for (int i = 1;i <= n;++i) cin >> x[i];
        for (int i = 1;i <= n;++i){
            dij(i);
            for (int j = 1;j <= n;++j) ans += (sum[j] == 2);
        }
        cout << ans / 2 << '\n';
    }
}
void subtask2(){
    while (t--){
        ans = 0;
        n = read(),d = read();
        for (int i = 1;i <= n;++i) x[i] = read();
        d /= (x[2] - x[1]);
        if (d == 0){
            cout << "0\n";
            continue;
        }
        for (int i = 1;i < n;++i){
            ll q = i / d;
            if (i % d == 0) continue;
            ll x = q + 1,h = d - i % d;
            if ((h == 1 && x + h - 1 == 2) || (h == x + h - 2 && x + h - 1 == 2))
                ans += n - i;
        }
        cout << ans << '\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c = read(),t = read();
    if (c <= 6) subtask1();
    else if (c == 11 || c == 12) subtask2();
    return 0;
}
