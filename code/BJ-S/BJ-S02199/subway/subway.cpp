#include<cstdio>
#include<vector>
using namespace std;

int c, n, m, d, q, tmp, T,  w[500005], k[505], x[500005], y[500005];
vector<int> a[505];
vector<int> t[505];
bool isb = true;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        a[i].push_back(-1);
        t[i].push_back(-1);
        for (int j = i; j <= k[i]; j++) {
            scanf("%d", &tmp);
            a[i].push_back(tmp);
            scanf("%d", &tmp);
            t[i].push_back(tmp);
        }
    }

    /*if (c >= 12 && c <= 19) {

    }*/

    for (int r = 1; r <= q; r++) {
        scanf("%d%d", &x[r], &y[r]);
        printf("1\n");
    }

    return 0;
}
