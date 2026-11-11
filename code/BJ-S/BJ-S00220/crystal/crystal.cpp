#include <bits/stdc++.h>
using namespace std;

long long n,m,sum;
vector<long long> a,w,v;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        a.push_back(x);
        sum+=x;
    }
    long long av=double(sum)/n;
    for(long long i:a)
    {
        w.push_back(abs(i-av));
        v.push_back(1);
    }
    long long s=w.size();
    vector<long long> dp(s+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=w[i];j<=m;j++)
        {
            if(dp[j]<dp[j-w[i]]+v[i])
            {
                dp[j]=dp[j-w[i]]+v[i];
            }
        }
    }
    cout<<dp[n-1];
    int fclose(0);
    return 0;
}
