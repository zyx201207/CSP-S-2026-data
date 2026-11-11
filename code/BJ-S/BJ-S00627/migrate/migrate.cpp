#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
const int inf = 0x3f3f3f3f;
int c, T;
int n, d, x[N];
int dis[N], cnt[N];
int ans = 0;
void solve(int k){
    for(int i = k; i <= n; ++i){
        dis[i] = inf; cnt[i] = 0;
    }
    dis[k] = 0; cnt[k] = 1;
    int l = k + 1;
    for(int i = k; i <= n; ++i){
        if(cnt[i] == 2) ++ans;
        // cout << k << " " << i << " " << dis[i] << " " << cnt[i] << endl;
        l = max(l, i + 1);
        for(int j = l; j <= n; ++j){
            if(x[j] - x[i] > d) break;
            // cout << i << " " << j << endl;
            if(dis[j] > dis[i] + 1){
                dis[j] = dis[i] + 1;
                cnt[j] = cnt[i];
            }else if(dis[j] == dis[i] + 1){
                cnt[j] += cnt[i];
                if(cnt[j] > 2) ++l;
                cnt[j] = min(cnt[j], 3ll);
            }
        }
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--){
        ans = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; ++i){
            cin >> x[i];
        }
        for(int i = 1; i <= n; ++i){
            solve(i);
        }
        cout << ans << "\n";
    }
    return 0;
}/*
T3 migrate 迁徙
考虑尝试转移步数 - 可以判断起始点对 - 但数量可能很多
若一个点可以够到很多点，则其部分点(k - 2)个无贡献
n<=2e6 像是纯线性做法捏
考虑n^3暴力-从每一个点出发一个个经过，其中每个点会对后面造成路径贡献 24pts
    考虑提前枚举直接双径关系，可以n^2扩展 40pts 吗?
对于性质A 显然只需特判 8pts
可以记录目前链上有多少点未被污染()
当且仅当两个岛屿同时被两边个不同方向岛屿覆盖
恰好有两条
*/