#include<bits/stdc++.h>
using namespace std;
#define long long int;
const int MAXN = 507;
const int MAXM = 5e5+7;
const int MAXD = 27;

typedef pair<int, int> PII;

int c, n, m, d, q;
int w[MAXM], t[MAXN][MAXN];
int t0[MAXM][MAXN];
vector<PII> G[MAXM];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(t, 0x3f, sizeof t);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i<=n; i++) t[i][i] = 0;
    for(int i = 1; i<=m; i++){
        scanf("%d", w+i);
    }
    for(int i = 1; i<=n; i++){
        int k;
        scanf("%d", &k);
        while(k--){
            int a, t1;
            scanf("%d%d", &a, &t1);
            G[a].push_back((PII){i, t1});
            t0[a][i] = t1;
        }
    }
    for(int i = 1; i<=m; i++){
        for(PII u:G[i]){
            for(PII v: G[i]){
                if(u.first!=v.first){
                    t[u.first][v.first] = min(t[u.first][v.first], u.second+v.second);
                    t[v.first][u.first] = min(t[v.first][u.first], u.second+v.second);
                }
            }
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            for(int k = 1; k<=n; k++){
                t[i][j] = min(t[i][j], t[i][k]+t[k][j]);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            t[i][j] = min(t[i][j], t[j][i]);
        }
    }
    while(q--){
        int x, y, ans = INT_MAX, u2, v2;
        scanf("%d%d", &x, &y);
        for(PII u: G[x]){
            for(PII v: G[y]){
                if(t[u.first][v.first]<ans){
                    ans = t[u.first][v.first];
                    u2 = u.first;
                    v2 = v.first;
                }
            }
        }
        printf("%d\n", ans+w[x]+w[y]+t0[x][u2]+t0[y][v2]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}