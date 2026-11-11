#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N], d[N], s[N];
ll n, m;
bool chk(int mid)
{
    bool flag = false;
    ll sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= mid-1) sum += d[i+1]*i;
        else
        {
            sum -= s[i]-s[i-mid+1];
            sum += d[i+1]*(mid-1);
        }


        // cout << sum << " ";
        if (i >= mid-1)
        {
            if (sum <= m)
            {
                // return true;
                flag = true;
            }
        }
    }

    if (flag) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    sort (a+1, a+n+1);

    for (int i = 2; i <= n; i++) d[i] = a[i]-a[i-1];
    // for (int i = 2; i <= n; i++) cout << d[i] << " ";

    // cout << endl;

    for (int i = 2; i <= n; i++) s[i] = s[i-1]+d[i];
    // for (int i = 2; i <= n; i++) cout << s[i] << " ";
    // cout << endl;

    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l+r+1)/2;

        // cout << "mid: " << mid << "  ";
        if (chk(mid))
        {
            l = mid;
        }
        else 
        {
            r = mid-1;
        }

        // cout << endl;
    }

    cout << l;
    return 0;
}