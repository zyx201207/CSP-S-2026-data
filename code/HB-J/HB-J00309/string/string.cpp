#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

long long a[N];
char c[N];
int n;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> c[i];

    long long l = 1, r = n;
    unsigned long long ans = 0;
    while (l < r)
    {
        if (c[l] == c[r])
        {
            if (a[l] >= a[r])
                a[l] -= a[r], a[r] = 0;

            else
                a[r] -= a[l], a[l] = 0;
        }
        else
        {
            if (a[l] >= a[r])
                ans += a[r], a[l] -= a[r], a[r] = 0;
            else
                ans += a[l], a[r] -= a[l], a[l] = 0;
        }
        l += (a[l] == 0), r -= (a[r] == 0);
    }
    cout << ans;
    return 0;
}
// when C[l] == C[r], it is a reverse string, the value + 0
// when (l == r) it is same continue and end;