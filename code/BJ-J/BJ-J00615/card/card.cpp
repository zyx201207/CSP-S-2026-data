#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],la[500005];
ll dp[500005],ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        la[a[i]]=i;
        dp[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=la[a[i]])
        {
            dp[la[a[i]]]+=dp[i];
        }
        else
        {
            ans[a[i]]+=dp[i];
            dp[i+1]+=dp[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
