#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m,a[N],dp[N],max_;
bool vis[N];
int f(int a,int b)
{
    int num1 = a,num2 = b,i = 0,sum = 0;
    while(min(num1,num2)!=0)
    {
        int t = 0;
        if(num1%2 == 1&&num2%2 == 1)
        {
            t = 1;
        }
        num1/=2,num2/=2;
        sum+=t*(pow(2,i));
        i++;
    }
    return sum;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int num = 0,nu;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>num)
        {
            nu = i;
            num = a[i];
        }
    }
    for(int i = 1;i<=n;i++)
    {
        dp[i] = 0;
    }
    dp[1] = num;
    //vis[1] = true;
    for(int i = 2;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(j == nu)
            {
                continue;
            }
            dp[i] = max(f(dp[i-1],a[j]),dp[i]);
            //if(f(dp[i-1],a[j])>dp[i])
            //{
               // vis[a[j]] = true;
            //}
        }
    }
    for(int i = 2;i<=n;i++)
    {
        max_ = max(max_,dp[i]);
    }
    cout<<max_;
    return 0;
}
