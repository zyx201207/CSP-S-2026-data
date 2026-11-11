#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500005];
int b[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    //    int mx = 0, mxid = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    //    for (int i = 1; i <= n; i++)
    //    {
    //        b[i] = a[i] - b[i - 1];
    //    }
    int mx = 0;
    int ans = 1;
    for (int l = 1, r = 1; l >= 1 && l <= r && r <= n;)
    {
        if (ans > mx)
        {
            mx = ans;
        }
        if (a[r] - a[l - 1] <= m)
        {
            r++;
            ans++;
        }
        if (a[r] - a[l - 1] > m)
        {
            l++;
            ans--;
        }
    }
    cout << mx;
}

