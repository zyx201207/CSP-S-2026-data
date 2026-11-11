#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,ans=1e18;
vector<ll> ve[100005];
void check(string s)
{
    ll vis[1005]={0};
    vector<ll> v;
    queue<ll> q;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            v.push_back(i+1);
            vis[i+1]=2;
        }
    }
    ll cnt=0;
    for(auto st:v)
    {
        if(vis[st]==2)
        {
            cnt++;
            q.push(st);
            vis[st]=0;
            while(!q.empty())
            {
                ll u=q.front();
                q.pop();
                for(auto ne:ve[u])
                {
                    if(vis[ne]==2)
                    {
                        q.push(ne);
                        vis[ne]=0;
                    }
                }
            }
        }
    }
    if(cnt>=2)return;
    ll dist[1005][1005]={0};
    queue<pair<ll,ll>> qq;
    ll sum=0;
    for(int st=1;st<=n;st++)
    {
        for(int i=1;i<=n;i++)vis[i]=0;
                //cout<<'D';
        qq.push({st,0});
        dist[st][st]=0;
        vis[st]=1;
        while(!qq.empty())
        {
            pair<ll,ll> u=qq.front();
            qq.pop();
            for(auto ne:ve[u.first])
            {
                if(vis[ne]==0)
                {
                    dist[st][ne]=u.second+1;
                    qq.push({ne,dist[st][ne]});
                    vis[ne]=1;
                }
            }
        }
        ll tmp=1e9;
        for(auto ed:v)
        {
            //cout<<dist[st][ed];
            tmp=min(dist[st][ed],tmp);
        }
        sum=max(sum,tmp);

    }
    ans=min(ans,sum);
}
void dfs(string s,ll ch)
{
    if(s.size()==n||ch==k)
    {
        ll len=s.size();
        for(int i=len;i<=n;i++)s+='0';
        check(s);
        return;
    }
    dfs(s+'0',ch);
    dfs(s+'1',ch+1);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c==7)
    {
        //solve1();
        return 0;
    }
    while(t--)
    {
        cin>>n>>t;
        for(int i=1;i<=n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        dfs("",0);
        cout<<ans<<endl;
        ans=1e18;
    }
    return 0;
}
