#include <bits/stdc++.h>
using namespace std;

long long w[500005];
long long k[505];

struct s {
    long long a, t;
    long long f;
} arr[505][100005];

struct s2 {
    long long x, y;
} arr2[500005];

long long ans;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    long long c, n ,m, d, q;
    cin >> c >> n >> m >> d >> q;

    for(long long i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for(long long i = 1; i <= n; i++) {
        cin >> k[i];

        for(long long j = 1; j <= k[i]; j++) {
            cin >> arr[i][j].a >> arr[i][j].t;
        }
    }

    for(long long i = 1; i <= q; i++) {
        cin >> arr2[i].x >> arr2[i].y;
    }

    long long minn = 500000005;
    for(long long i = 1; i <= q; i++) {
        bool ba = false, bi = false;
        ans = 0;
        ans = ans + w[arr2[i].x] + w[arr2[i].y];

        vector<long long> aa, bb;
        long long time = 0;
        for(long long j = 1; j <= n; j++) {
            for(long long f = 1; f <= k[j]; f++) {
                if(arr[j][f].a == arr2[i].x) {
                    aa.push_back(j);
                    break;
                }
                if(arr[j][f].a == arr2[i].y) {
                    bb.push_back(j);
                    break;
                }
            }
        }

        for(long long ax : aa) {
            for(long long bx : bb) {
                for(long long ii = 1; ii <= k[ax]; ii++) {
                    for(long long jj = 1; jj <= k[bx]; jj++) {
                        if(arr[ax][ii].a == arr[bx][jj].a) {
                            time = 0;
                            for(long long iii = 1; iii <= ii; iii++) {
                                time += arr[ax][iii].t;
                            }
                            for(long long jjj = jj; jjj <= k[bx]; jjj++) {
                                    time += arr[bx][jjj].t;
                                if(arr[bx][jjj].a == arr2[i].y) {
                                    break;
                                }
                            }

                            long long ttt = 0;
                            for(long long kkk = 1; kkk <=jj; kkk++) {
                                ttt += arr[ax][kkk].t;
                            }
                            minn = min({time, minn, ttt});
                        }
                    }
                }
            }
        }

        cout << ans + minn << endl;
    }

    return 0;
}
