#include<bits/stdc++.h>
const int N = 5e3+5;
using namespace std;
#define ll long long
int TEST;
namespace Pinball{
    int n, a[N];
namespace Pre{
    ll d, b[N];
    void qwq(){
        cin >> n >> d;
        for (int i = 1;i <= n;i++) cin >> b[i];
        for (int i = 1, j;i <= n;i++){
            j = i;
            while (j < n && b[j + 1] - b[i] <= d) ++j;
            a[i] = j;
        }
    }
}
    int dis[N][N], f[N][N];
    void Purgatory(){
        Pre::qwq();
        for (int i = 1;i <= n;i++){
            for (int j = i;j <= n;j++){
                dis[i][j] = f[i][j] = 0;
            }
        }
        for (int i = n;i;i--){
            if (a[i] == i) continue;
            for (int j = i + 1;j <= n;j++){
                if (j <= a[i]) dis[i][j] = 1;
                else dis[i][j] = dis[a[i]][j] + 1;
                if (a[j] == j) break;
            }
        }
        int ans = 0;
        for (int i = n;i;i--){
            if (a[i] == i) continue;
            for (int j = n;j > i;j--){
                if (!dis[i][j]) continue;
                if (j <= a[i]){
                    f[i][j] = 1;
                    continue;
                }
                f[i][j] = f[a[i]][j];
                if (f[i][j] == 3) continue;
                if (a[i] > i + 1 && dis[a[i]][j] == dis[a[i] - 1][j]){
                    f[i][j] = min(f[i][j] + f[a[i] - 1][j], 3);
                }
                if (a[i] > i + 2 && dis[a[i]][j] == dis[a[i] - 2][j]){
                    f[i][j] = min(f[i][j] + f[a[i] - 2][j], 3);
                }
                if (f[i][j] == 2){
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T = 1;
    cin >> TEST >> T;
	while (T--) Pinball::Purgatory();
	return 0;
}