#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int inf=0x3f3f3f3f;
void solve()
{
    int n;
    long long D;
    cin>>n>>D;
    vector<ll>a(n+10);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    ll ans=0;
    for(int st=1;st<=n;++st)
    {
        vector<int>dis(n+10,inf);
        dis[st]=0;
        vector<int>cnt(n+10);
        cnt[st]=1;
//        queue<int>que;
//        que.push(st);
//        int l=-1,r=-1;
//        while(!que.empty())
        for(int u=st;u<=n&&dis[u]!=inf;++u)
        {
//            int u=que.front();
//            que.pop();
            if(cnt[u]==2)
            {
                ++ans;
//                if(l==-1)
//                    l=u;
//                r=max(r,u);
            }
//            cerr<<st<<' '<<u<<" -- "<<dis[u]<<' '<<cnt[u]<<endl;
            for(int v=u+1;v<=n&&a[v]-a[u]<=D;++v)
                if(dis[v]==inf)
                    dis[v]=dis[u]+1,cnt[v]=cnt[u];//,que.push(v);
                else if(dis[v]==dis[u]+1)
                    cnt[v]=min(3,cnt[v]+cnt[u]);
        }

//        for(int i=l;i<=r;++i)
//            assert(cnt[i]==2);
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}
