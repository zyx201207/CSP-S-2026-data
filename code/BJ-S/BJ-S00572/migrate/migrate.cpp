#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using pi=pair<int,ll>;
#define pb push_back
#define fi first
#define se second
ll n,d;
int i,j,k;
vl x;
vl dp;
deque<int>q;
int hh[2];
void solve()
{
    cin>>n>>d;
    x.clear();
    dp.clear();
    x.resize(n+1,0);
    dp.resize(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    ll ans=0;
    q.clear();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) dp[j]=-1;
        dp[i]=0;
        q.clear();
        q.push_back(i);
        bool fl=0;
        for(j=i+1;j<=n;j++)
        {
            while(!q.empty()&&x[j]-x[q.front()]>d)
            {
                q.pop_front();
            }
            if(q.empty()) break;
            if(!fl&&q.size()>=2)
            {
                for(int k=0;k<=1;k++)
                {
                    hh[k]=q.front();
                    q.pop_front();
                }
                if(dp[hh[0]]==dp[hh[1]])
                {
                    if(q.empty()||(!q.empty()&&dp[q.front()]!=dp[hh[0]]))
                    {
                        ans++;
                        fl=1;
                    }
                }
                q.push_front(hh[1]);
                q.push_front(hh[0]);
            }
            if(fl)
            {
                int xxx=q.front();
                q.pop_front();
                if(dp[xxx]!=dp[q.front()])
                {
                    ans++;
                }
                else
                {
                    break;
                }
                q.push_front(xxx);
            }
            dp[j]=dp[q.front()]+1;
            q.push_back(j);
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*
0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
0 1
6 12
-10 -6 -2 2 6 10
*/