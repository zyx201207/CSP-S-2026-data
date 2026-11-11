#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], num[500005], cnt[500005];
int maxn = 0;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    int top = 0, c = a[2] - a[1];
    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (i > 2) {
            if (a[i] - a[i - 1] != c) {
                f = false;
            }
        }
        if (a[i] != num[top]) {
            top++;
            num[top] = a[i];
        }
        cnt[top]++;
    }
    int l = 1, r = 1;
    if (f) {
        int j = 1;
        int ans = cnt[1];
        long long tm = 0;
        while(m - tm >= cnt[j + 1] * (num[1] - num[j + 1]) && j < top) {
            tm += cnt[j + 1] * (num[1] - num[j + 1]);
            ans += cnt[j + 1];
            j++;
        }
        int d = (m - tm) / (num[1] - num[j + 1]);
        if (j == top) {
            d = 0;
        }
        ans += d;
        maxn = max(maxn, ans);
    } else {
        int ans = cnt[r];
        long long tm = 0;
        while (r <= n) {
            if (r == top) {
                maxn = max(maxn, ans);
                break;
            }
            if (m - tm >= cnt[r + 1] * (num[l] - num[r + 1]) && r < top) {
                tm += cnt[r + 1] * (num[l] - num[r + 1]);
                ans += cnt[r + 1];
                r++;
            } else {
                int d = (m - tm) / (num[l] - num[r + 1]);
                maxn = max(maxn, ans + d);
                int cnts = 0;
                for (int i = l + 1; i <= r; i++) {
                    cnts += cnt[i];
                }
                tm -= (num[l] - num[l + 1]) * cnts;
                ans -= cnt[l];
                l++;
            }
        }
    }
    cout << maxn;
    return 0;
}