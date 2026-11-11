#include <bits/stdc++.h>

using namespace std;

#define int long long

using i64 = long long;
using pii = pair<int, int>;

#define fi first 
#define se second
#define mkp make_pair

const int N = 320;
const int INF = 0x3f3f3f3f3f3f3f3f;

int c, t; 
int n, x[N], d;
int dis[N][N], cnt[N][N]; 
void S(){
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) dis[i][j] = INF, cnt[i][j] = 0; 
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(x[j] - x[i] <= d){
                dis[i][j] = cnt[i][j] = 1; 
                dis[j][i] = cnt[j][i] = 1; 
            } 
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                if(i != j && i!= k && j != k){
                    if(dis[i][k] > dis[i][j] + dis[j][k]){
                        dis[i][k] = dis[i][j] + dis[j][k];
                        cnt[i][k] = cnt[i][j] * cnt[j][k]; 
                    }
                    else if(dis[i][k] == dis[i][j] + dis[j][k]){
                        cnt[i][k] += cnt[i][j] * cnt[j][k]; 
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if(dis[j][i] < INF && cnt[j][i] == 2) ans++; 
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--) S(); 

    return 0; 
}
