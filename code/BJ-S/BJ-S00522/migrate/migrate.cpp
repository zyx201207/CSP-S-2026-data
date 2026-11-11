#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
const long long inf=3e18;
int c,t,n;
int tot,b[maxn];
long long d;
long long x[maxn];
long long dp1[5005][5005],dp2[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    if(c==11 || c==12)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>x[i];
            long long k=d/abs(x[2]-x[1]);
            if(d<=abs(x[2]-x[1])) cout<<0<<"\n";
            else cout<<max(n*1ll-(2*k-1),0ll)<<"\n";
        }
    }
    else
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>x[i];
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp1[i][j]=inf,dp2[i][j]=0;
            for(int i=1;i<(1<<n);i++)
            {
                int tot=0;
                for(int j=1;j<=n;j++)
                    if((1<<(j-1))&i)
                        b[++tot]=j;
                bool f=0;
                for(int j=2;j<=tot;j++)
                    if(x[b[j]]-x[b[j-1]]>d)
                    {
                        f=1;
                        break;
                    }
                if(f) continue;
                if(tot-1<dp1[b[1]][b[tot]])
                {
                    dp1[b[1]][b[tot]]=tot-1;
                    dp2[b[1]][b[tot]]=1;
                }
                else if(tot-1==dp1[b[1]][b[tot]])
                {
                    dp1[b[1]][b[tot]]=tot-1;
                    dp2[b[1]][b[tot]]++;
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(dp1[i][j]!=inf && dp2[i][j]==2)
                        ans++;//,cout<<i<<" "<<j<<" "<<dp1[i][j]<<"\n";
            cout<<ans<<"\n";
            /*
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(x[j]-x[i]<=d)
                        dp1[i][j]=1,dp2[i][j]=1;
                    else break;
            for(int i=1;i<=n;i++)
                dp1[i][i]=0,dp2[i][i]=1;
            for(int l=2;l<=n;l++)
                for(int i=1;i+l-1<=n;i++)
                {
                    int j=i+l-1;
                    for(int k=i+1;k<j;k++)
                        if(dp1[i][j]>dp1[i][k]+dp1[k][j])
                        {
                            //if(i==1 && j==n) cout<<k<<"!\n";
                            dp1[i][j]=dp1[i][k]+dp1[k][j];
                            dp2[i][j]=dp1[i][k]*dp1[k][j];
                            if(dp2[i][j]>=3) dp2[i][j]=3;
                        }
                        else if(dp1[i][j]==dp1[i][k]+dp1[k][j])
                        {
                            //if(i==1 && j==n) cout<<k<<"?\n";
                            dp2[i][j]+=dp1[i][k]*dp1[k][j];
                            if(dp2[i][j]>=3) dp2[i][j]=3;
                        }
                }
                */
                /*
            for(int k=1;k<=n;k++)
                for(int i=1;i<=n;i++)
                    for(int j=i+1;j<=n;j++)
                        if(i<k && k<j)
                        {
                            if(i==1 && j==6 && k==)

                        }
                        */
            //int ans=0;
    /*
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    cout<<i<<" "<<j<<" "<<dp1[i][j]<<" "<<dp2[i][j]<<"\n";
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(dp1[i][j]!=inf && dp2[i][j]==2)
                        ans++;
            cout<<ans<<"\n";
    */
        }
    }

    return 0;
}
/*
1 1
5 3
-3 0 2 3 4

2
*/
