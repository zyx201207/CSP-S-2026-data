#include<iostream>
#include<cmath>
using namespace std;
int m,n;
int a[200005],dp[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    dp[0]=1073741823;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp[j]=max(dp[j],dp[j-1]&a[i]);

        }
    }
    cout<<dp[m];
    return 0;
}