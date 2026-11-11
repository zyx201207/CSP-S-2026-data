#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
ll a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>m)
        {
            sum-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}