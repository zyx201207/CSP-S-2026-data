#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,d,dis[N],cnt[N],a[N];
vector <int> g[N];
/*
struct node
{
    int x,w;
};
bool operator <(node x,node y)
{
    return x.w>y.w;
}
*/
void spfa(int s)
{
    memset(cnt,0,sizeof cnt);
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    cnt[s]=1;
    queue <int> q;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i:g[t])
        {
            if(dis[i] > dis[t]+1)
            {
                cnt[i]=1;
                dis[i]=dis[t]+1;
                q.push(i);
            }
            else if(dis[i] == dis[t]+1)
            {
                cnt[i]+=cnt[t];
                q.push(i);
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            g[i].clear();
        }
        int l=1;
        for(int r=2;r<=n;r++)
        {
            if(l<r && a[r]-a[l]>d) l++;
            for(int k=l;k<r;k++)
            {
                if(a[r]-a[l]<=d)
                    g[k].push_back(r);
            }
        }
        for(int i=1;i<=n;i++)
        {
            spfa(i);
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }

}
