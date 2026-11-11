#include <iostream>
#include <cstdio>
#include<vector>
#include<cstring>

using namespace std;

int x[200005],ans=0;
int n,d;
int c,t;
struct node
{
    int z,sl;
};
node dp[2005][2005];

void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j].z=0x7f;
			dp[i][j].sl=1;
		}
	}
    for(int i=1;i<=n;i++)
    {
        dp[i][i].z=0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int l=1;l<=n;l++)
        {
            for(int r=1;r<=n;r++)
            {
                if(x[k+1]-x[k]>d)
                {
                    continue;
                }
                if(dp[l][r].z==dp[l][k].z+dp[k+1][r].z+1)
                {
                    dp[l][r].sl++;
                }
                if(dp[l][r].z>dp[l][k].z+dp[k+1][r].z+1)
                {
                    dp[l][r].sl=1;
                }
                dp[l][r].z=min(dp[l][r].z,dp[l][k].z+dp[k+1][r].z+1);
            }
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        floyd();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][j].sl==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

