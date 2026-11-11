#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,s[500005],r=1,cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int l=1;l<=n;l++)
    {
        long long cnt2=cnt;
        cnt=cnt2-(a[r]-a[l]);
        while(r<n&&cnt<=m)
        {
            r++;
            cnt+=(r-l)*(a[r]-a[r-1]);
        }
        ans=max(ans,r-l);
    }
    cout<<ans;
    return 0;
}
