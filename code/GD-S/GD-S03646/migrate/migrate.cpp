#include<bits/stdc++.h>
// #include<cassert>
using namespace std;
typedef long long ll;
const int MAXN=2000005;
int n,cnt[MAXN],rcnt[MAXN],l[MAXN],cans[MAXN];
ll d,a[MAXN];
vector<array<ll,2>>p[MAXN];
bool vis[MAXN];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C{},T{};cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        ll t{},sum{},ans{};
        priority_queue<array<ll,3>>q;
        for(int i=1;i<=n;i++)p[i].clear(),rcnt[i]=-1,cnt[i]=0;
        q.push({0,0,1}),cnt[1]=1;
        for(int i=2;i<=n;i++)
        {
            vector<int>v;
            while(q.size()&&q.top()[0]+t+a[i]-a[i-1]>d)
            {
                auto h=q.top();q.pop();
                ll w=h[0]+t,s=h[1],x=h[2];
                v.push_back(x),vis[x]=1;
                if(rcnt[x]==-1)rcnt[x]=cnt[x];
                cnt[x]--;
                if(a[i]-a[i-1]<=d)p[x].push_back({a[i]-a[i-1],s+1});
                if(i>=3&&a[i-1]-a[i-2]<w&&a[i]-a[i-2]<=d)p[x].push_back({a[i]-a[i-2],s+1});
                if(i>=4&&a[i-1]-a[i-3]<w&&a[i]-a[i-3]<=d)p[x].push_back({a[i]-a[i-3],s+1});
            }
            t+=a[i]-a[i-1];
            for(int j:v)
            {
                if(!vis[j])continue;
                vis[j]=0;
                sum-=(rcnt[j]==2),rcnt[j]=-1;
                if(!cnt[j])
                {
                    sort(p[j].begin(),p[j].end());
                    cnt[j]=min(3,(int)p[j].size());
                    for(int k=0;k<cnt[j];k++)q.push({p[j][k][0]-t,p[j][k][1],j});
                }
                sum+=(cnt[j]==2),p[j].clear();
                if(cnt[j]==2)l[j]=i;
            }
            cnt[i]=1;
            q.push({-t,0,i});
            ans+=sum;
        }
        cout<<ans<<'\n';
    }
    return 0;
}