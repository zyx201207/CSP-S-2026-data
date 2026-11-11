#include<iostream>
#include<algorithm>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,ans=1,l=1,r=0;
    long long m,sum=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        r++;
        sum+=a[i];
        while(l<=r&&1ll*(r-l+1)*a[i]-sum>m)
        {
            sum-=a[l];
            l++;
        }
        if(l<=r&&1ll*(r-l+1)*a[i]-sum<=m) ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
