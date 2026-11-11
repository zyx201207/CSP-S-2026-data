#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5;
int n, d;
int x[N];
int f[5005][5005];
int g[5005][5005];

bool check1() {
    int d = x[2]-x[1];
    for(int i=2; i<=n; i++) {
        if(x[i]-x[i-1]!=d) return false;
    }
    return true;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t --) {
        cin >> n >> d;
        for(int i=1 ;i<=n; i++) {
            cin >> x[i];
        }
        if(x[n]-x[1]<=d) {
            cout << 0 << endl;
        } else if(check1()) {
            int t = d/(x[2]-x[1]);
            int sum = 0;
            for(int i=1; i<t; i++) {
                if(i+t<n && (i+t)&1) {
                    sum = sum+n-(i+t);
                }
            }
            cout << sum << endl;
        } else {
            int cnt = 0;
            memset(f, 0x3f, sizeof(f));
            memset(g, 0, sizeof(g));
            for(int i=1; i<=n; i++) {
                for(int j=i+1; j<=n; j++) {
                    if(x[j]-x[i]<=d) {
                        f[i][j] = 1;
                    }
                }
            }
            for(int k=1; k<=n; k++) {
                for(int i=1; i<=n; i++) {
                    for(int j=1;j<=n; j++) {
                        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
                    }
                }
            }
            for(int k=1; k<=n; k++) {
                for(int i=1; i<=n; i++) {
                    for(int j=1;j<=n; j++) {
                        if(f[i][k]+f[k][j] == f[i][j]) {
                            g[i][j] ++;
                        }
                    }
                }
            }
            for(int i=1; i<=n; i++) {
                for(int j=i+1; j<=n; j++) {
                    if(g[i][j] == 2) {
                        cnt ++;
                    }
                }
            }
            cout << cnt << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
