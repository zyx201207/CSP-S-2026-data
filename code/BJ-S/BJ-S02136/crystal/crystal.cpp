# include <bits/stdc++.h>
# define int long long
const int N = 5e5 + 5;
using namespace std;
int a[N];
int n, m;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    int c = 0;
    a[0] = a[1];
    for(int j = 1, i = 1; i <= n; i++)
    {
        c += (i - j) * (a[i] - a[i - 1]);
        while(c > m)
        {
            c -= (a[i] - a[j]);
            j++;
        }
        //cout << j << " " << i << " " << c << "\n";
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;
}

/*
5 8
-2 -1 2 2 7
*/
