#include<bits/stdc++.h>
using namespace std;
struct Node
{
    long long val,to;
};
long long w[500002],dp[502][502];//dp[i][j]:从i号线到j号线的最小（把一个号线看成一个大点）
vector<Node> g[500002];//g[i]:站厅i经过哪几号线（<=20）及到它们的时间
long long c,n,m,d,q;
void Floyd()
{
    for(long long k=1;k<=n;k++)//中转点
    {
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
        cin>>w[i];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
            dp[i][j]=1e18;
        dp[i][i]=0;
    }
    for(long long i=1;i<=n;i++)
    {
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++)
        {
            long long aij,tij;
            cin>>aij>>tij;
            g[aij].push_back({tij,i});
        }
    }
    for(long long i=1;i<=m;i++)//枚举每个站厅
    {
        long long len=g[i].size();
        for(long long j=0;j<len-1;j++)
        {
            for(long long k=j+1;k<len;k++)
            {
                long long s=g[i][j].to,t=g[i][k].to,hao1=g[i][j].val,hao2=g[i][k].val;
                dp[s][t]=min(dp[s][t],hao1+hao2),dp[t][s]=min(dp[t][s],hao1+hao2);
            }
        }
    }
    Floyd();
    while(q--)
    {
        long long xi,yi,len1,len2,minn=1e18;
        cin>>xi>>yi;
        len1=g[xi].size(),len2=g[yi].size();
        for(long long i=0;i<len1;i++)//从这走
        {
            for(long long j=0;j<len2;j++)//到这里
            {
                long long s=g[xi][i].to,t=g[yi][j].to,hao1=g[xi][i].val,hao2=g[yi][j].val;
                minn=min(minn,dp[s][t]+hao1+hao2+w[xi]+w[yi]);
            }
        }
        cout<<minn<<"\n";
    }
    return 0;
}