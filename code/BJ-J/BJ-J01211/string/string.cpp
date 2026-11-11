#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 2e5;

int n;

ll a[N + 5];

char c[N + 5];

int l, r;

ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] >> c[i];
    }
    l = 1, r = n;
    while (l < r)
    {
        if (a[l] < a[r])
        {
            if (c[l] != c[r]) ans += a[l];
            a[r] -= a[l];
            l++;
        }
        else if (a[l] == a[r])
        {
            if (c[l] != c[r]) ans += a[l];
            l++;
            r--;
        }
        else
        {
            if (c[l] != c[r]) ans += a[r];
            a[l] -= a[r];
            r--;
        }
    }
    cout << ans << '\n';
    return 0;
}

