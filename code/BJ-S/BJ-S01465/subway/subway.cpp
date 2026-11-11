#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fir first
#define sec second
#define mkp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;
vector<vector<pii> > mp;//mp[i]:di i ge zhan jing guo duo shao tiao di tie  ;  dis[i]:di i ge zhan di tie dao zhan ting de zui duan ju li.
ll tme[500001];
ll dp[501][501];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c,n,m,d,q;
    ll num,t1,t2;
    cin>>c>>n>>m>>d>>q;
    mp.resize(m+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++) cin>>tme[i];
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        for(int j=1;j<=num;j++)
        {
            cin>>t1>>t2;
            mp[t1].push_back(mkp(i,t2));
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(pii j:mp[i])
        {
            for(pii k:mp[i])
            {
                if(j.fir!=k.fir) dp[j.fir][k.fir]=min(dp[j.fir][k.fir],j.sec+k.sec);
                else dp[j.fir][k.fir]=0;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--)
    {
        ll ans=9223372036854775807LL;
        cin>>t1>>t2;
        for(pii i:mp[t1])
        {
            for(pii j:mp[t2])
            {
                ans=min(ans,dp[i.fir][j.fir]+i.sec+j.sec);
            }
        }
        ans+=tme[t1]+tme[t2];
        cout<<ans<<endl;
    }
    cout<<flush;
    return 0;
}
