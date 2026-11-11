#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long inf = 1e18;
const long long mod = 998244353;
const long long N = 5e5 + 5;
int n , m;
int cnt = 0 , ans = 1;
int a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    int l = 1;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    sort(a + 1 , a + 1 + n , less<int>());
    for(int i = 1 ; i <= n ; i++)
    {
        cnt += a[i];
        while(a[i] * (i - l + 1) - cnt > m)cnt -= a[l++];
        ans = max(ans , i - l + 1);
    }
    cout << ans;
    return 0;
}
