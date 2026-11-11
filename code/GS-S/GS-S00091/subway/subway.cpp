#include <iostream>
#include <cstdio>
#include<vector>
#include<cstring>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> a[5005];
vector<int> t[5005];
int k1[5005];
struct node
{
    int q,z,m;
};

node dp[25][25];

void floyd()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j].z=0x7f7f7f7f;
            dp[i][j].q=0,dp[i][j].m=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        dp[i][i].z=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=k1[j];k++)
            {
                if(a[j][k]==i)
                {
                    dp[i][i].q=j;
                    dp[i][i].m=j;
                }
            }
        }

    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[dp[i][k].m][k]!=0&&a[dp[k][j].q][k]!=0)
                    dp[i][j].z=min(dp[i][j].z,dp[i][k].z+dp[k][j].z+t[dp[i][k].m][k]+t[dp[k][j].q][k]);
                if(dp[i][j].z==(dp[i][k].z+dp[k][j].z+t[dp[i][k].m][k]+t[dp[k][j].q][k]))
                {
                    dp[i][j].q=dp[i][k].q;
                    dp[i][j].m=dp[k][j].m;
                }
            }
        }
    }
    return ;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        k1[i]=k;
        for(int j=1;j<=k;j++)
        {
            int a1,t1;
            cin>>a1>>t1;
            a[i].push_back(a1);
            t[i].push_back(t1);
        }
    }
    floyd();
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y].z+w[x]+w[y]<<endl;
    }
    return 0;
}
