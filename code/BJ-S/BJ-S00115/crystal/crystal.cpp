#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005], maxn;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
    {
        ll x=m;
        for(ll j=i+1;j<=n;j++)
        {
            x-=a[i]-a[j];
            if(x<=0||j==n)
            {
                maxn=max(maxn,j-i+(x>=0?1:0));
                break;
            }
        }
    }
    cout << maxn << endl;
    return 0;
}
