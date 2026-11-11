#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int w[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int T,n;
    cin>>n>>T;
    int mx=1073741823;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i];
        mx=max(mx&w[i],w[i]&w[i-1]);
    }
    dp[1]=mx;
    for (int i=1;i<=n;i++)
    {
        int t=1;
        for (int j=T;j>=t;j--)
        {
            dp[j]=max(dp[j],dp[j-t]&w[i]);
        }
    }
    cout<<dp[T];
    return 0;
}
