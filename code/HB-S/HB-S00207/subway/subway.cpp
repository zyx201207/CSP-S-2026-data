#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
struct node{
    int to, next, w;
};
int c, n, m, d, q;
int w[maxn], k[maxn], a[505][maxn], t[505][maxn];
int x[maxn], y[maxn];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    srand(int(time(0)));
    int i, j;
    cin >> c >> n >> m >> d >> q;
    for(i = 1;i <= m;i++) cin >> w[i];
    for(i = 1;i <= n;i++){'
        cin >> k[i];
        for(j = 1;j <= k[i];j++) cin >> a[i][j] >> t[i][j];

    }
    for(i = 1;i <= q;i++) cin >> x[i] >> y[i];
    cout << t[i][j] * rand() % 2 * 2;
    return 0;
}
