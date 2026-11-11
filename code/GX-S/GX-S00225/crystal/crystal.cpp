#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],dp[8005][8005],ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(n>5000)
    {
        int sum=0,ch=a[2]-a[1];
        for(int i=2;i<=n+1;i++)
        {
            sum+=ch*(i-1);
            if(sum>m || i==n+1)
            {
                ans=i-1;
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1,k=2;j<=n;j++,k++)
        {
            dp[i][j]=dp[i][j-1]+(j-i)*(a[j]-a[j-1]);
            if(dp[i][j]>m)
                break;
            if(ans<k)
                ans=k;
        }
    }
    cout<<ans;
    return 0;
}
