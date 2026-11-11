#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 5e3 + 10;
const long long INF = 1e18;

int n;
long long d, a[N];
long long floyd[M][M];
long long cnt[M][M];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        if(n >= 5e3){
            cout << 0 << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                floyd[i][j] = INF;
                cnt[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++)cin >> a[i], floyd[i][i] = 0, cnt[i][i] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i; j >= 1 && (a[i] - a[j] <= d); j--){
                floyd[i][j] = floyd[j][i] = 1;
                cnt[i][j] = cnt[j][i] = 1;
            }
        }
        for(int len = 2; len <= n; len++){
            for(int l = 1; l <= n - len + 1; l++){
                int r = l + len - 1;
                // if(floyd[l][r] == 1)continue;
                for(int mid = l; mid <= r; mid++){
                    if(floyd[l][mid] == INF || floyd[mid][r] == INF)continue;
                    long long nw = floyd[l][mid] + floyd[mid][r];
                    long long nwcnt = cnt[l][mid] * cnt[mid][r];
                    if(nw < floyd[l][r]){
                        floyd[l][r] = floyd[r][l] = nw;
                        cnt[l][r] = cnt[r][l] = nwcnt;
                    }
                    else if(nw == floyd[l][r]){
                        cnt[l][r] += nwcnt;
                        cnt[r][l] += nwcnt;
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(cnt[i][j] == 2)ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}