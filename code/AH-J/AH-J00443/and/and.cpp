#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],maxn,k1=2,k2;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]-a[i-1]!=1)
        {
            k1=1;
        }
        maxn=max(a[i],maxn);
    }
    if(k1==1)
    {
        cout<<maxn;
    }
    else
    {
        cout<<maxn-1;
    }
    return 0;
}
