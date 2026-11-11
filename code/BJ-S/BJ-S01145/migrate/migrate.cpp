#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
long long c,t,n,d;
vector<int> v[5005];
long long dis[N],vit[N];
struct Node
{
    int u,val;
    bool operator < (const Node &tmp_1) const
    {
        return val>tmp_1.val;
    }
};
long long ru[N];
void dij(int s)
{
    for(int i=1;i<=n;i++) dis[i]=-1,vit[i]=ru[i]=0;
    dis[s]=0;
    priority_queue<Node> q;
    q.push({s,dis[s]});
    while(q.size())
    {
        int u=q.top().u;
        q.pop();
        if(vit[u]) continue;
        vit[u]=1;
        for(int i=0;i<v[u].size();i++)
        {
            int vd=v[u][i];
            if(vit[vd]) continue;
            if(dis[vd]==-1 || dis[vd]>dis[u]+1)
            {
                dis[vd]=dis[u]+1;
                q.push({vd,dis[vd]});
            }
        }
    }
}
int cm[N];
void tuop(int s)
{
    for(int i=1;i<=n;i++) vit[i]=cm[i]=0;
    queue<int> qp;
    qp.push(s);
    vit[s]=1;
    while(qp.size())
    {
        int u=qp.front();
        qp.pop();
        for(int i=0;i<v[u].size();i++)
        {
            int vd=v[u][i];
            if(dis[vd]==dis[u]+1) cm[vd]+=max(cm[u],1),ru[vd]--;//cout<<vd<<" "<<u<<" "<<s<<"\n",
            if(!ru[vd] && !vit[vd]) qp.push(vd),vit[vd]=1;
        }
    }
}

long long ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i],v[i].clear();
        if((c!=13 && c!=14) || n*n<2000000)
        {
            for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(abs(a[i]-a[j])<=d) v[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++)
        {
            dij(i);
            for(int j=1;j<=n;j++)
            {
                if(j==i) continue;
                for(int k=0;k<v[j].size();k++)
                {
                    int vd=v[j][k];
                    if(dis[vd]==dis[j]-1) ru[j]++;
                }
            }
            tuop(i);
            for(int j=1;j<=n;j++)
            {
                if(cm[j]==2) ans++;//cout<<j<<" "<<i<<" "<<dis[j]<<"\n";
            }
        }
        cout<<ans/2<<"\n";
        }
        else
        {
            sort(a+1,a+n+1);
            int l=a[1];
            for(int i=1;i<=n;i++)
            {
                while(a[i]-a[l]>2*d) l++;
                ans+=l-1;
            }
            cout<<ans;
        }
    }
    return 0;
}
