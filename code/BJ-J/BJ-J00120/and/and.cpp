#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[20005][20005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=20)
    {
        //mn^2
        for(int i=1;i<=n;i++)
        {
            dp[i][1]=a[i];
        }
        for(int i=1;i<=n;i++)//shudeliang
        {
            for(int j=2;j<=m;j++)//daxiao
            {
                if(i<j)
                {
                    dp[i][j]=0;
                }
                else if(i==j)
                {
                    dp[i][j]=a[i]&dp[i-1][j-1];
                }
                else    //i>j
                {
                    int maxand=0;
                    for(int k=1;k<i;k++)
                    {
                        maxand=max(maxand,a[i]&dp[k][j-1]);
                    }
                    dp[i][j]=max(maxand,dp[i-1][j]);
                }
            }
        }
        cout<<dp[n][m]<<endl;
        return 0;
    }
    else if(m==1)
    {
        cout<<a[n]<<endl;
        return 0;
    }
    else if(m==2)
    {
        int maxans=0;
        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
                maxans=max(maxans,a[i]&a[j]);
        cout<<maxans<<endl;
        return 0;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    else 
    {
        cout<<a[n-m+1];
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}