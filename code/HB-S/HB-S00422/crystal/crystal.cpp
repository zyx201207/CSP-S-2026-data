#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,ans,cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1;
    ans=1;
    cnt=0;
    for(long long i=2;i<=n;i++)
    {
        long long o=(a[i]-a[i-1])*(i-l);
        cnt=cnt+o;
        while(cnt>m)
        {
            cnt=cnt+a[l]-a[i];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
