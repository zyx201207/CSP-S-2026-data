#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long dp[1005][1005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;




    while(t--)
    {





        long long sum=0;
        long long n,d;
        cin>>n>>d;
        memset(a,0,sizeof a);
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++)cin>>a[i];

        for(int i=1;i<=n;i++)//shanglouti
        {


            dp[i][0]=1;

            for(int j=i;j<=n;j++){

                for(int k=j;a[j]-a[k]<=d,k>=1;k--){
                    dp[i][j]+=dp[i][k];
                }

            }


        }

        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=n;j++){
                if(dp[i][j]==2)sum++;
            }

        }
        cout<<sum<<endl;





    }
    return 0;
}

