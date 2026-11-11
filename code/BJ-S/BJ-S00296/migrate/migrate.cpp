#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,c,dis;
vector<vector<int> > d(5005,vector<int>(5005)),a(5005,vector<int>(5005)),ans(5005,vector<int>(5005));
vector<int> isl(200005);
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>dis;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) d[i][j]=a[i][j]=1E9,ans[i][j]=0;
        }
        for(int i=1;i<=n;i++) d[i][i]=a[i][i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>isl[i];
            // if(abs(isl[i]-isl[i-1])<=dis) d[i][i-1]=d[i-1][i]=a[i-1][i]=a[i][i-1]=min(a[i][i-1],abs(isl[i]-isl[i-1]));
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(abs(isl[i]-isl[i-1])<=dis) d[i][i-1]=d[i-1][i]=a[i-1][i]=a[i][i-1]=min(a[i][i-1],abs(isl[i]-isl[i-1]));
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(d[i][k]<1E9&&d[k][j]<1E9&&d[i][k]+d[k][j]<d[i][j]) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j||i==k||j==k) continue;
                    if(d[i][k]<1E9&&d[k][j]<1E9&&d[i][k]+d[k][j]==d[i][j]) ans[i][j]++;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                ans[i][j]--;
                // cout<<i<<" "<<j<<" "<<ans[i][j]<<" "<<d[i][j]<<"\n";
                sum+=ans[i][j]*(ans[i][j]+1)/2;
            }
        }
        cout<<sum<<"\n";
    }
}