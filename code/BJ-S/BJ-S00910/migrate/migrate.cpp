#include<iostream>
using namespace std;
long long c,t,n,a[2000001],d,dp[2000001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&d);
        dp[1]=1;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        long long ans=0;

        for(int i=2;i<=n;i++)
        {
            long long tmp=0,fl=0;
            for(int j=i-1;j>=1;j--)
            {
                tmp+=a[j+1]-a[j];fl++;
                if(tmp>d&&tmp<=2*d&&fl%2==1&&fl!=1)
                {
//                    cout<<j<<' '<<i<<' '<<tmp<<"& ";
                    ans++;
                    break;
                }

            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
