#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll a[N],s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    ll cur = 0;
    int l = n,r = n,maxn = 0;
    while(l > 0)
    {
        if(cur <= m)
        {
            l--;
            cur += a[r] - a[l];
        }
        else
        {
            maxn = max(maxn,r - l);
            cur -= (r - l) * (a[r] - a[r - 1]);
            r--;
        }
    }
    maxn = max(maxn,r - l);
    cout << maxn << endl;
    return 0;
}
