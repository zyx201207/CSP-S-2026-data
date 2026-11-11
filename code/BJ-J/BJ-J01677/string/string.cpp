#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ll sum = 0;
    cin >> n;
    for (ll i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    ll ans = 0;
    for (ll i = 1,j = n,ii = 0,jj = sum;i <= j;i++)
    {
        //cout << ii << ' ' << jj << ' ' << ans << "\n";
        ii = ii + a[i];
        while (jj-a[j]+1 > sum-ii+1)
        {
            if (c[i] != c[j])
            {
                ans += a[j];
            }
            jj -= a[j];
            j--;
        }
        if (c[i] != c[j]) ans += ii+jj-sum;
        a[j] -= ii+jj-sum;
        jj -= ii+jj-sum;
    }
    cout << ans;
    return 0;
}
