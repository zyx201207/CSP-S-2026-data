#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005],f[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    long long t=m,nw=n-1,cnt=0;
    for(int i=n;i>=2;i--)
    {
        while(nw)
        {
            if(t<a[i]-a[nw]) break;
            t-=(a[i]-a[nw]);
            nw--;
            cnt++;
        }
        f[i]=cnt+1;
        t+=cnt*(a[i]-a[i-1]);
        if(cnt) cnt--;
    }
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=1;
        dp[i]=max(f[i],dp[i-1]);
    }
    cout << dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
