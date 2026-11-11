#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
template <class TT>
using vc=vector<TT>;
const long long INF=1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    long long test_case, n, m, d, q;
    cin >> test_case >> n >> m >> d >> q;
    vc<long long> en(m+1);
    for(long long i=1;i <= m;i++){
        cin >> en[i];
    }
    vc<vc<pair<long long, long long>>> rt(n+1);
    vc<vc<pair<long long, long long>>> v(m+1);
    for(long long i=1;i <= n;i++){
        long long k;
        cin >> k;
        for(long long j=1;j <= k;j++){
            long long a, t;
            cin >> a >> t;
            rt[i].push_back({a, t});
            v[a].push_back({i, t});
        }
    }
    vc<vc<long long>> dis(n+1, vc<long long>(n+1, INF));
    for(long long i=1;i <= m;i++){
        for(auto xmp : v[i]){
            long long x=xmp.fir, xt=xmp.sec;
            for(auto xmp : v[i]){
                long long y=xmp.fir, yt=xmp.sec;
                dis[x][y]=min(dis[x][y], xt+yt);
            }
        }
    }
    for(long long i=1;i <= n;i++){
        dis[i][i]=0;
    }
    for(long long k=1;k <= n;k++){
        for(long long i=1;i <= n;i++){
            long long s=dis[i][k];
            for(long long j=1;j <= n;j++){
                dis[i][j]=min(dis[i][j], s+dis[k][j]);
            }
        }
    }
    // for(int i=1;i <= n;i++){
    //     for(int j=1;j <= n;j++){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(long long i=1;i <= q;i++){
        long long a, b;
        cin >> a >> b;
        long long ans=INF;
        for(auto xmp : v[a]){
            long long x=xmp.fir, xt=xmp.sec;
            for(auto xmp : v[b]){
                long long y=xmp.fir, yt=xmp.sec;
                ans=min(ans, en[a]+en[b]+xt+yt+dis[x][y]);
            }
        }
        cout << ans << "\n";
    }
}