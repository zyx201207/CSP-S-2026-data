#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int m, n, c, k, T, dd;
int w[N];
int h[N], ver[N], nxt[N], ege[N], tot;
void add(int x, int y, int z){
    ver[++tot] = y;
    ege[tot] = z;
    nxt[tot] = h[x];
    h[x] = tot;
}
ll d[510][510];
int a[30][2], r, b[30][2], rr;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> dd >> T;
    for(int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    int x, y, z;
    for(int i = 1; i <= n; i++){
        scanf("%d", &k);
        for(int j = 1; j <= k; j++){
            scanf("%d %d", &x, &z);
            add(x, m + i, z);
        }
    }
    memset(d, 0x3f, sizeof d);
    for(int x = 1; x <= m; x++){
        r = 0;
        for(int i = h[x]; i; i = nxt[i]){
            a[++r][0] = ver[i] - m;
            a[r][1] = ege[i];
        }
        for(int i = 1; i <= r; i++)
            for(int j = 1; j < i; j++)
                d[a[j][0]][a[i][0]] = d[a[i][0]][a[j][0]] = min(d[a[i][0]][a[j][0]], 1ll * a[i][1] + a[j][1]);
    }
    for(int i = 1; i <= n; i++)d[i][i] = 0;
    for(int p = 1; p <= n; p++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
    for(int i = 1; i <= T; i++){
        ll ans = 1e18;
        scanf("%d %d", &x, &y);
        r = rr = 0;
        for(int i = h[x]; i; i = nxt[i]){
            a[++r][0] = ver[i] - m;
            a[r][1] = ege[i];
        }
        for(int i = h[y]; i; i = nxt[i]){
            b[++rr][0] = ver[i] - m;
            b[rr][1] = ege[i];
        }
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= rr; j++)
                ans = min(ans, a[i][1] + b[j][1] + d[a[i][0]][b[j][0]]);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
