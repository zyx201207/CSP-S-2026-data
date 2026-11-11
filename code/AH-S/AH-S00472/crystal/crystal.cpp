#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll maxn = 5e5+5;
ll n,m,a[maxn],ans=-1;

void find()
{
    for (ll i=n;i>=1;i--)
    {
        if (a[i]==a[i+1] || i<ans) continue;
        ll val=0;
        bool flag=0;
        for (ll j=i;j>=1;j--)
        {
            val+=a[i]-a[j];
            if (val>m)
            {
                flag=1;
                ans=max(ans,i-j);
                break;
            }
        }
        if (!flag)
        {
            ans=max(ans,i);
        }
    }
}

int main ()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    find();
    cout<<ans;
    return 0;
}