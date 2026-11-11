#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,d,a[200005],ans;
pair<int,int>dp[200005];
deque<int>q;

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++) dp[j]={0,0};
            q.clear();
            q.push_back(i);
            dp[i]={0,1};
            for(int j=i-1;a[j+1]-a[j]<=d&&j>=1;j--)
            {
                while(!q.empty()&&a[q.front()]-a[j]>d) q.pop_front();
                dp[j].first=dp[q.front()].first+1;
                for(int k=0;k<=q.size()-1;k++) if(dp[q[k]].first+1==dp[j].first) dp[j].second+=dp[q[k]].second;
                if(dp[j].second==2) ans++;
                while(!q.empty()&&dp[q.back()].first>dp[j].first) q.pop_back();
                q.push_back(j);
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}