#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
vector<vector<long long> > a(505,vector<long long>(505,1E9)),dp(505,vector<long long>(505,1E9));
vector<long long> j(500005);
struct node
{
    long long x,t;
};
vector<vector<node> > sub(505,vector<node>(500005));
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>j[i];
    }
    for(int i=1;i<=n;i++)
    {
        a[i][i]=dp[i][i]=0;
        long long k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>sub[i][j].x>>sub[i][j].t;
        }
        dp[sub[i][1].x][sub[i][2].x]=dp[sub[i][1].x][sub[i][2].x]=a[sub[i][1].x][sub[i][2].x]=a[sub[i][1].x][sub[i][2].x]=min(a[sub[i][1].x][sub[i][2].x],sub[i][1].t+sub[i][2].t);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][k]<1E9&&dp[k][j]<1E9&&dp[i][k]+dp[k][j]<dp[i][j]) dp[i][j]=dp[i][k]+dp[k][j]; 
            }
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<dp[l][r]+j[l]+j[r]<<"\n";
    }
}