#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll v,step;
};
ll c,t,n,d,x[5005],dis[5005][5005],vis[5005],cnt[5005][5005];
vector<node> ve[5005];
void bfs(ll st)
{
    queue<node> q;
    q.push({st,0});
    dis[st][st]=0;
    vis[st]=1;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        for(auto ne:ve[u.v])
        {
            if(u.step+1==dis[st][ne.v])
            {
                cnt[st][ne.v]++;
            //    cout<<vis[ne.v]<<" "<<u.v<<"->"<<ne.v<<" "<<u.step+1<<" "<<dis[st][ne.v]<<" "<<cnt[st][ne.v]<<endl;
            }
            if(!vis[ne.v])
            {
                dis[st][ne.v]=u.step+1;
                q.push({ne.v,dis[st][ne.v]});
                vis[ne.v]=1;
                //cout<<u.v<<"->"<<ne.v<<" "<<u.step+1<<endl;
            }
        }
    }
}
ll __abs__(ll x,ll y)
{
    if(x-y<=0)return y-x;
    else return x-y;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&__abs__(x[i],x[j])<=d)
                {
                    ve[i].push_back({j,1});
                    //cout<<i<<" "<<j<<endl;
                }

            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                vis[j]=0;
            }
            bfs(i);
        }
        for(int i=1;i<=n;i++)
        {
            //for(int j=1;j<=n;j++)
            //{
                //cout<<dis[i][j]<<" ";
            //}
            ve[i].clear();
            //cout<<endl;
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&cnt[i][j]==1)
                {
                    //cout<<i<<" "<<j<<endl;
                    cnt[j][i]=0;
                    ans++;
                }
                cnt[i][j]=0;
                dis[i][j]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
