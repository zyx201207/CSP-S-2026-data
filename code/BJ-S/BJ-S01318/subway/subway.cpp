#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q, cnt, head[500005];
int w[500005];
int cnt2, cnt3, op1[21][2], op2[21][2], dis[501][501];
struct edge {
    int to, val, nxt;
} edge[500005];

void add(int from, int to, int val){
    edge[++cnt] = {to, val, head[from]};
    head[from] = cnt;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1, p, q; j <= k; j++)
            cin >> p >> q, add(p, i, q);
    }
    for (int i = 1; i <= m; i++){
        cnt2 = 0;
        for (int h = head[i]; h; h = edge[h].nxt){
            cnt2++;
            op1[cnt2][0] = edge[h].to, op1[cnt2][1] = edge[h].val;
        }
        for (int j = 1; j <= cnt2; j++)
            for (int k = j + 1; k <= cnt2; k++)
                dis[op1[k][0]][op1[j][0]] = dis[op1[j][0]][op1[k][0]] = min(dis[op1[j][0]][op1[k][0]], op1[j][1] + op1[k][1]);
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--){
        int x, y;
        cin >> x >> y;
        cnt2 = 0;
        for (int h = head[x]; h; h = edge[h].nxt){
            cnt2++;
            op1[cnt2][0] = edge[h].to, op1[cnt2][1] = edge[h].val;
        }
        cnt3 = 0;
        for (int h = head[y]; h; h = edge[h].nxt){
            cnt3++;
            op2[cnt3][0] = edge[h].to, op2[cnt3][1] = edge[h].val;
        }
        int ans = 1e18;
        for (int i = 1; i <= cnt2; i++)
            for (int j = 1; j <= cnt3; j++)
                ans = min(ans, op1[i][1] + op2[j][1] + dis[op1[i][0]][op2[j][0]]);
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
