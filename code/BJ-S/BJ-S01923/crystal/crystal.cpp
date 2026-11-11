#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+8;
ll n, m;
ll a[MAXN], c[MAXN], pfx[MAXN];
int check(int pos)
{
    ll k = 0;
    ll sum = 0, cnt = 1;
    for(int i = pos;i >= 2;i--)
    {
        k += c[i];
        sum += k;
        if(sum > m)
        {
            return cnt;
        }
        cnt++;
    }
    return cnt;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 2;i <= n;i++) c[i] = a[i] - a[i-1];

    if(n <= 5000)
    {
        ll ans = 1;
        for(int i = 2;i <= n;i++)
        {
            ans = max(ans, 1ll * check(i));
        }
        cout << ans;
        return 0;
    }
    ll d = a[2] - a[1];
    for(int i = 1;i <= 20000;i++)
    {
        if(1ll * (d + 1ll * i * d) * 1ll * i / 2 > m)
        {
            cout << i-1;
            break;
        }

    }
    return 0;
}
