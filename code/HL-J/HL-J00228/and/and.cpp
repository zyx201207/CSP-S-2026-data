#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ok(n, 1), tmp(n, 0);
    for(int dig = 30; dig >= 0; dig--)
    {
        long long sha = (1ll << dig);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(!ok[i]) continue;
            if((a[i] & sha) >= sha)
            {
                cnt++;
                tmp[i] = 1;
            }
        }
        if(cnt >= m)
        {
            ok = tmp;
        }
        for(int i = 0; i < n; i++) tmp[i] = 0;
    }
    int ans = (1ll << 31) - 1;
    for(int i = 0; i< n; i++)
    {
        if(ok[i]) ans &= a[i];
    }
    cout << ans << endl;
    return 0;
}
