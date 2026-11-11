#include<bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010]={0};
int b[200100];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if((a[i]&a[j])>dp[i])
            {
                dp[i]=a[i]&a[j];
                b[i]=a[j];
            }
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(maxn<dp[i])
        {
            maxn=dp[i];
        }
    }
    cout<<maxn<<endl;
    return 0;
}
