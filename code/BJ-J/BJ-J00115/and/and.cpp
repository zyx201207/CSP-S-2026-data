#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[8001][8001],now=-1,pow_two[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
long long a[2000001];
bool flag=true,is_pow[2000001];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=2000000;i++)
    {
        is_pow[i]==false;
    }
    for(int i=1;i<=20;i++)
    {
        is_pow[pow_two[i]]=true;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        now=max(now,a[i]);
        dp[i][1]=now;
        if(is_pow[a[i]+1]==false)
        {
            flag=false;
        }
    }
    if(n<=8000)
    {
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=i&&j<=m;j++)
            {
                if(i-1>=j)
                {
                    dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1]&a[i]));
                }
                else
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
                }
            }
        }
        cout<<dp[n][m];
    }
    else
    {
        if(flag==true)
        {
            sort(a+1,a+n+1,cmp);
            cout<<a[m];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}