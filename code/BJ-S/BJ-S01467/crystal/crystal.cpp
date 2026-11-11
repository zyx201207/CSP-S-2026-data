#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long dp[1000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    priority_queue<int,vector<int>,greater<int>>q;
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    for(long long i=1;i<=n;i++)
    {
        a[i]=q.top();
        q.pop();
    }
    dp[0]=0;
    for(long long i=1;i<=n;i++)
    {
        long long mm=m,ans=1;
        for(long long j=i-1;j>0;j--)
        {
            mm-=(a[i]-a[j]);
            if(mm<0)
            {
                break;
            }
            ans++;
        }
        dp[i]=max(dp[i-1],ans);
    }
    cout<<dp[n];
}