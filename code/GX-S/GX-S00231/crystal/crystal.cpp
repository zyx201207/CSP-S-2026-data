#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];
ll ans=LLONG_MIN;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ll cnt=0,num=0;
        for(int j=i;j>=1;j--)
        {
            if(cnt+(a[i]-a[j])<=m)
            {
                cnt+=(a[i]-a[j]);
                num++;
            }
            else break;
        }
        ans=max(ans,num);
    }
    cout<<ans;
    return 0;
}
