#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
long long a[MAXN];
long long aptapt[MAXN];
long long cntcnt[MAXN];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    long long maxn = -1e9 - 10, minn = 1e9 + 10;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    sort(a+1, a+n+1);
    for(long long i = minn; i <= maxn + m; i++) {
        long long apt = 0, cnt = 0;
        for(int j=1; j<= n; j++) {
            if(a[j] <= i) {
                apt += (i - a[j]);
                aptapt[i] = apt;
                cnt++;
                cntcnt[i] = cnt;
            }
        }
        if(aptapt[i-1] <= m && aptapt[i] > m) {
            cout << cntcnt[i-1] << endl;
            return 0;
        }
    }
    return 0;
}
