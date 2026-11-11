#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,a[2000005],b[2000005],b2[2000005],cnt,num,ans,c[2000005],dp[5005][5005];
void check(int x)
{
    for(int i=1;i<=n;i++)
    {
        dp[x][i]=0;
    }
    dp[x][0]=1;
    c[x]=0;
    for(int i=x+1;i<=n;i++)
    {
        c[i]=10000000000000;
        if(a[i]-a[i-1]>d)
        {
            break;
        }
        for(int j=i-1;j>=x;j--)
        {
            if(b2[i]-b2[j]<=d)
            {
                for(int l=c[j]+1;l<=c[j]+2;l++)
                {
                    dp[i][l]=0;
                }
            }
            else
            {
                break;
            }
        }
        for(int j=i-1;j>=x;j--)
        {
            if(b2[i]-b2[j]<=d)
            {
                for(int l=c[j]+1;l<=c[j]+2;l++)
                {
                    dp[i][l]+=dp[j][l-1];
                }
                c[i]=min(c[i],c[j]+1);
            }
            else
            {
                break;
            }
        }
        if(dp[i][c[i]]==2)
        {
            ans++;
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i!=1)
            {
                b[i]=a[i]-a[i-1];
            }
        }
        for(int i=2;i<=n;i++)
        {
            b2[i]=b2[i-1]+b[i];
        }
        if(C==13||C==14)
        {
            int x=0,y=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
                {
                    x=i;
                    break;
                }
            }
            for(int i=n;i>=1;i--)
            {
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
                {
                    y=i;
                    break;
                }
            }
            cout<<(x-1)*(n-y)<<"\n";
            return 0;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            check(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
