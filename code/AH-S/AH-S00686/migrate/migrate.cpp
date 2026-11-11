#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e3 + 5;
const ll INF = 0x7f7f7f7f7f7f7f7f;

ll dist[N][N];
int f[N][N];
int c, t;
int n, d;
int x[N];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        int head = 1;
        memset(dist, 0x7f, sizeof dist);
        int ans = 0;
        f[1][2] = 2;
        for (int i = 1; i <= n; i++) f[i][i] = 0;
        for (int i = 2; i <= n; i++){
            while (x[i] - x[head] > d) head++;
            for (int j = 1; j <= head - 1; j++){
                dist[j][i] = min(dist[j][head] + 1, INF);
                if (head == i) {
                    f[j][i] = 2;
                    continue;
                }
                if (head == i - 1 || dist[j][head] != dist[j][head+1]){
                    if (f[j][head] == 1){
                        f[j][i] = 1;
                        ans++;
                    } 
                    f[j][i] = f[j][head];
                }
                else {
                    if (f[j][head] == 2 || f[j][head+1] == 2) f[j][i] = 2;
                    else if (f[j][head] == 1 && f[j][head+1] == 1) f[j][i] = 2;
                    else if (f[j][head] == 0 && f[j][head+1] ==0) {
                        f[j][i] = 1;
                        ans++;
                    }
                    else f[j][i] = 2;
                }
            }
            for (int j = head; j <= i; j++){
                dist[j][i] = 1;
                f[j][i] = 0;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}