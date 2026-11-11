#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 300 + 7;
int c, t, n, dis[N][N][N];
LL d, a[N];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        int ans = 0;
        cin >> n >> d;
        memset(dis, 0, sizeof dis);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) {
            int now = i, lst = i, cnt = 0, j = 0;
            //cout << now << ' ';
            while(j < n) {
                j = upper_bound(a + now + 1, a + n + 1, a[now] + d) - a - 1;
                if(j <= now) break;
                j = min(j, n);
                //cout << j << ' ';
                if(now - 1 > i) {
                    int now2 = now - 1, lst2 = now - 1, cnt2 = cnt, k = 0;
                    //cout << '\n' << now2 << ' ';
                    while(k < n) {
                        k = upper_bound(a + now2 + 1, a + n + 1, a[now2] + d) - a - 1;
                        if(k <= now2) break;
                        k = min(k, n);
                        //cout << k << ": ";
                        cnt2++;
                        for(int o2 = lst2 + 1; o2 <= k; o2++)
                            dis[i][o2][cnt2]++;
                        now2 = k;
                        lst2 = now2;
                    }
                }
                if(now - 2 > i) {
                    int now2 = now - 2, lst2 = now - 2, cnt2 = cnt, k = 0;
                    while(k < n) {
                        k = upper_bound(a + now2 + 1, a + n + 1, a[now2] + d) - a - 1;
                        if(k <= now2) break;
                        k = min(k, n);
                        cnt2++;
                        //cout << k << ": ";
                        for(int o2 = lst2 + 1; o2 <= k; o2++)
                            dis[i][o2][cnt2]++;
                        now2 = k;
                        lst2 = now2;
                    }
                }
                cnt++;
                for(int o = lst + 1; o <= j; o++)
                    dis[i][o][cnt]++;
                now = j;
                lst = now;
            }
            for(j = i + 1; j <= n; j++)
                for(int k = 1; k <= n; k++)
                    if(dis[i][j][k] > 0) {
                        //cout << dis[i][j][k] << ' ';
                        if(dis[i][j][k] == 2) ans++;
                        else break;
                    }
            //cout << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}
