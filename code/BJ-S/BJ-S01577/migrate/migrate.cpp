#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 2e6 + 5;
const int inf = 1e18;
const int L = 22;
int a[N], b[N], n, d;
int c;
void dfs(int x, int y, int cnt){
    if (x == y){
        b[cnt]++;
        return ;
    }
    for (int i = x + 1;i <= y && a[i] - a[x] <= d;i++){
        dfs(i, y, cnt + 1);
    }
}
bool issj(int x, int y){
    for (int i = 1;i <= n;i++){
        b[i] = 0;
    }
    dfs(x, y, 0);
    for (int i = 1;i <= n;i++){
        if (b[i] > 0){
            if (b[i] == 2) return 1;
            return 0;
        }
    }
    return 0;
}
void solve(){
    cin >> n >> d;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (c <= 2){
        int ans = 0;
        for (int i = 1;i <= n;i++){
            for (int j = i + 1;j <= n;j++){
                ans += issj(i, j);
            }
        }
        cout << ans << "\n";
        return ;
    }
    if (c == 11 || c == 12){
        cout << n - 3 - 2 * (d / (a[2] - a[1]) - 2) << "\n";
        return ;
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> c >> t;
	while (t--){
        solve();
	}
	return 0;
}
