#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[500010],c[500010],ml[500010];
int lk[300010];
int d[500010];
int cnt = 0;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    bool flaga = true;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if (a[i] < a[i-1]) {
            flaga = false;
        }
    }
    int cntb = 0;
    for (int i=1;i<n;i++) {
        if (a[i] != a[i+1]) {
            cntb++;
        }
    }
    if (flaga) {
        for (int i=1;i<=n;i++) {
            ans[a[i]] = i;
        }
    } else if (n <= 5000) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                lk[j] = 0;
            }
            cnt = 0;
            for (int j=i;j<=n;j++) {
                if (lk[a[j]]) {
                    while (d[cnt] != a[j]) {
                        lk[d[cnt]]--;
                        cnt--;
                    }
                } else {
                    lk[a[j]]++;
                    cnt++;
                    d[cnt] = a[j];
                }
            }
            for (int j=1;j<=cnt;j++) {
                ans[d[j]]++;
            }
        }
    } else if (cntb <= 5000) {
        int cou = 0,nn = 0;
        for (int i=1;i<=n;i++) {
            cou++;
            if (i == n || a[i] != a[i+1]) {
                nn++;
                c[nn] = a[i];
                ml[nn] = cou;
                cou = 0;
            }
        }
        for (int i=1;i<=nn;i++) {
            for (int j=1;j<=m;j++) {
                lk[j] = 0;
            }
            cnt = 0;
            for (int j=i;j<=nn;j++) {
                if (lk[c[j]]) {
                    while (d[cnt] != c[j]) {
                        lk[d[cnt]]--;
                        cnt--;
                    }
                } else {
                    lk[c[j]]++;
                    cnt++;
                    d[cnt] = c[j];
                }
            }
            for (int j=1;j<=cnt;j++) {
                ans[d[j]] += ml[i];
            }
        }
    } else if (m <= 2) {
        if (m == 1) {
            cout << n << "\n";
            return 0;
        } else {
            for (int i=1;i<=n;i++) {
                if (a[i] == 1 && a[n] == 1) {
                    ans[1]++;
                } else if (a[i] == 2 && a[n] == 2) {
                    ans[2]++;
                } else {
                    ans[1]++;
                    ans[2]++;
                }
            }
        }
    }
    for (int i=1;i<=m;i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}