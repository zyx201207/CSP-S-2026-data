#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500008], cf[500008];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++)
    {
        cf[i] = a[i] - a[i - 1];
    }

    int ans = 1;
    int l = 0, r = 0;
    long long need = 0;
    while(l <= n - 1 && r <= n - 1)
    {
        while(need + cf[r + 1] * (l - r + 1) <= m && r <= n - 1) // next r
        {
            r++;
            need += cf[r + 1] * (r - l + 1);
        }
        if (r - l + 1 > ans)
        {
            ans = r - l + 1;
        }
        l ++;
        r = l;
        need = 0;
    }
    cout << ans;

    return 0;
}
