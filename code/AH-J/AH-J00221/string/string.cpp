#include<bits/stdc++.h>

using namespace std;

int n;
int a[200005];
char s[200005][10];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> s[i] + 1;
    }
    long long ans = 0;
    int cnt1 = 1, cnt2 = n;
    while (cnt1 != cnt2) {
        if (a[cnt1] >= a[cnt2]) {
            if (s[cnt1][1] != s[cnt2][1])
                ans += a[cnt2];
            a[cnt1] -= a[cnt2];
            a[cnt2] = 0;
            cnt2--;
        }
        else {
            if (s[cnt1][1] != s[cnt2][1])
                ans += a[cnt1];
            a[cnt2] -= a[cnt1];
            a[cnt1] = 0;
            cnt1++;
        }
    }
    cout << ans << "\n";
    return 0;
}
