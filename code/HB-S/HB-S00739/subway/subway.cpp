#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
using namespace std;
const int maxn = 510, maxm = 5e5 + 10;
const int inf = INT_MAX / 2;

int c, n, m, d, q;
int w[maxm];
int a[maxn][maxm], t[maxn][maxm];
int x, y;
struct Edge {
    int from;
    int to;
};
vector <Edge> g;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n ;i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        cout << w[x] + w[y] << endl;
    }
	return 0;
}
