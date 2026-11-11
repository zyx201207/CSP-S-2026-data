#include<bits/stdc++.h>
#define int long long
using namespace std;
int ccccc,n,m,d,q;
const int ad=5e5;
int w[500010];
struct node
{
    int id,t;
};
struct cmp
{
    bool operator()(const node &a,const node &b)const
    {
        return a.t>b.t;
    }
};
vector<node> u[1001000];
map<pair<int,int>,int> mp;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>ccccc>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            u[i+ad].push_back({a,t});
            u[a].push_back({i+ad,t});
        }
    }
    for(int t=1;t<=m;t++)
    {
        priority_queue<node,vector<node>,cmp> pq;
        bool v[m+ad]={0};
        pq.push({t,0});
        while(pq.size())
        {
            int now=pq.top().id,ti=pq.top().t;
            pq.pop();
            if(v[now]||mp[{t,now}])continue;
            mp[{t,now}]=mp[{now,t}]=ti;
            v[now]=1;
            for(int i=0;i<u[now].size();i++)
            {
                int len=ti+u[now][i].t;
                int tto=u[now][i].id;
                if(!v[tto])pq.push({tto,len});
            }
        }
    }
    while(q--)
    {
        int fr,to;
        cin>>fr>>to;
        cout<<mp[{fr,to}]+w[fr]+w[to]<<endl;
    }
    return 0;
}