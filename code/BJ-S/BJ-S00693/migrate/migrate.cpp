#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e6 + 5;
int T;
int c, n, d, a[MAXN];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while (T--)
    {
        int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (c >= 11 && c <= 12)
        {
            int div = d / (a[2] - a[1]);
            if (div <= 1 || div * 2 > n) {cout << 0 << endl; continue;}
            cout << n - div * 2 + 1 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 3; j <= n; j++)
            {
                vector<int> v1, v2;
                int k = j, sum = 0;
                while (a[k] - a[i] > d)
                {
                    int pre = k;
                    for (int l = k; a[pre] - a[l] <= d; l--) k = l;
                    if (pre == k) {sum = 2; break;}
                    v1.push_back(k);
                }
                k = i;
                while (a[j] - a[k] > d)
                {
                    int pre = k;
                    for (int l = k; a[l] - a[pre] <= d; l++) k = l;
                    if (pre == k) {sum = 2; break;}
                    v2.push_back(k);
                }
                reverse(v1.begin(), v1.end());
                if (v1.size() != v2.size()) continue;
                for (int i = 0; i < v1.size(); i++)
                    sum += abs(v1[i] - v2[i]);
                if (sum == 1) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}