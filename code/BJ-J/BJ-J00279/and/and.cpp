#include<bits/stdc++.h>
using namespace std;
int andx[200001],dp[200001];
int m,n;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>andx[i];
    }
    dp[0]=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp[j]=max(dp[j],dp[j-1]&andx[i]);
        }
    }
    cout<<dp[m];
}
