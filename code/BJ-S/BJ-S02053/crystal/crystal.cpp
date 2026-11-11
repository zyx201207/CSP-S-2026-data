# include <bits/stdc++.h>
using namespace std;
# define ll long long
ll c, t, n, d;
ll x[501000];


int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        if (d >= 2)
        {
            cout << max((ll)0, n-d*2+1) << endl;
        }
    }
    return 0;
}
