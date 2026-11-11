#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const ll N=2e5+5;//zhuyi ll
ll a[N];
char c[N];
ll sum;
ll n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    sum/=2;
    ll l=1,r=n;
    ll ans=0;
    while(l<r)
    {
        if(a[l]>=a[r])
        {
            if(c[l]!=c[r])
                ans+=a[r];
            a[l]-=a[r];
            r--;
            if(a[l]==0)
                l++;
        }
        else if(a[l]<a[r])
        {
            if(c[l]!=c[r])
                ans+=a[l];
            a[r]-=a[l];
            l++;
            if(a[r]==0)
                r--;
        }
    }
    cout<<ans;
    return 0;
}
