#include<bits/stdc++.h>
using namespace std;
const int M = 2e3+10;

long long dis[M][M];
int n, m, d, q;
long long w[M];
void solve(){
    for(int neww = 2; neww <= m; neww++){
        for(int oldd = 1; oldd < neww; oldd++){
            for(int k = 1; k <= m; k++){
                dis[oldd][k] = min(dis[oldd][k], dis[oldd][neww] + dis[neww][k]);
                dis[k][oldd] = dis[oldd][k];
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)cin >> w[i];

    int ki;
    memset(dis, 0x7f, sizeof(dis));
    for(int i = 1; i <= n; i++){
        cin >> ki;
        int tt[M][2];
        for(int j = 1; j <= ki; j++){
            cin >> tt[j][0] >> tt[j][1];
        }
        for(int j = 1; j < ki; j++){
            for(int k = j+1; k <= ki; k++){
                dis[tt[k][0]][tt[j][0]] = dis[tt[j][0]][tt[k][0]] = tt[j][1] + tt[k][1];
            }
        }
    }

    solve();

    int x, y;
    for(int i = 1; i <= q; i++){
        cin >> x >> y;
        cout << w[x] + w[y] + dis[x][y] << '\n';
    }
    return 0;
}
