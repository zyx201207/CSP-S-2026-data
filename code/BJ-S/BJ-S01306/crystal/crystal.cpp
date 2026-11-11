#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ans,cnt,l,r;
ll a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1;
    r=1;
    cnt=0;
    while(l<=n&&r<=n)
    {
        cnt+=(r-l)*(a[r]-a[r-1]);
        while(cnt>m)
        {
            cnt-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans<<endl;
    return 0;
}
