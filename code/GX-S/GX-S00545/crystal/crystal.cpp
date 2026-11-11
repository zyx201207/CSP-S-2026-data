#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0, cnt = 0, var;
    for (int i = 0, j = 0; j < n; j++) {
        while (m < (a[j] - var) * cnt && i < j) {
            m += var - a[i++];
            cnt--;
        }
        if (i == j) {
            cnt = 1;
            var = a[j];
        } else {
            m -= (a[j] - var) * cnt++;
            var = a[j];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
