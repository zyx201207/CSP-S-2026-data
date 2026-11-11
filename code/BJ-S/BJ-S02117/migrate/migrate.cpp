#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int INF=1000000005;
/*struct node
{
    int v,w;
};
vector<node>a[1000005];
int dis[1000005];
void dijkstra(int )*/
int dp[5005][5005][2],a[5005];
//when read i;
//dp[i][j][0]:num of different min ways to j ; dp[i][j][1]:min length to j
int n,d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,ans=0;
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int k=1;k<=n-2;++k)
        {

            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    dp[i][j][1]=INF;
            /*for(int i=1;i<=n;++i)
            {
                dp[i][i][0]=1,dp[i][i][1]=0;/*dp[i-1][i][1]=0,dp[i-1][i][0]=1;*//*
            }*/
            dp[k-1][k][1]=0,dp[k-1][k][0]=1;
            for(int i=k;i<=n;++i)
            {
                for(int j=i+1;j<=n;++j)
                {
                    if(a[j]-a[i]>d)break;
                    if(dp[i-1][i][1]+1 < dp[i-1][j][1])
                    {
                        dp[i][j][1]=dp[i-1][i][1]+1;
                        dp[i][j][0]=dp[i-1][i][0];
                    }
                    if(dp[i-1][i][1]+1 == dp[i-1][j][1])
                    {
                        dp[i][j][1]=dp[i-1][j][1]+1;// unchanged
                        dp[i][j][0]=dp[i-1][i][0]+dp[i-1][i][1];
                    }
                    if(dp[i-1][i][1]+1 > dp[i-1][j][1])
                    {
                        dp[i][j][1]=dp[i-1][j][1];// unchanged
                        dp[i][j][0]=dp[i-1][i][0];
                    }
                }
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                    cout<<dp[i][j][0]<<" ";
                cout<<endl;
            }
            cout<<endl;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                    cout<<dp[i][j][1]<<" ";
                cout<<endl;
            }
            cout<<endl;
            for(int i=k+1;i<=n;++i)
                if(dp[i-1][i][0]==2)
                    ans++;
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
