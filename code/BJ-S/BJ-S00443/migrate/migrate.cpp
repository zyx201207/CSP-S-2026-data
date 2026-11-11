#include<iostream>
using namespace std;
const long long MX=2e6+10;
long long c,t,n,d,a[MX],dp[MX],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            long long now=0;
            long long mi=1e18;
            bool bk=0;
            for(int j=i-1;j>=1;j--)
            {
                if(a[i]-a[j]>d)
                {
                    break;
                }
                bk=1;
                if(dp[j]+1<mi)
                {
                    mi=dp[j]+1;
                    now=1;
                }
                else if(dp[j]+1==mi)
                {
                    now++;
                }
            }
            if(bk)
            {
                if(now==2)
                {
                    ans++;
                }
                dp[i]=mi;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
