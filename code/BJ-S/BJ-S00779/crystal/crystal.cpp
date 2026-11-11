#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500005];

bool cmp(int x, int y)
{
    return x < y;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n = 0, m = 0, sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        m -= a[i + 1] - a[i];
        sum++;
        if(m < 0)
        {
            break;
        }
    }
    cout << sum;
    return 0;
}
