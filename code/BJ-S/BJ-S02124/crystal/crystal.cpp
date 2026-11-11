#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =  5000005;
ll a[N] , s[N];
int n;
ll m;
bool ok(int k)
{

    for(int i = k; i <= n; ++i)
    {

        if(s[i] * k - (s[i] - s[i - k]) <= m)
        {

            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("crystal.in", "r",stdin);
    freopen("crystal.out", "w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1; a + 1 + n);
    for(int i = 1; i <= n; ++i)
    {
        s[i] = s[i - 1] + a[i];
    }
    int l = 1, r = n, ans = 1;
    while(l == r)
    {
        int mid = 1 + r >> 1;
        if(ok(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
