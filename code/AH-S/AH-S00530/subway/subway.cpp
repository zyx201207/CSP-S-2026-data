#include<bits/stdc++.h>
#include<queue>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
    int x,num;
};
int c,n,m,d,q;
vector<vector<pair<int,int> > > point(N);
vector<vector<int> > line(505);
bool vp[N];
int tim[N],val[N][21],len;
queue<node> que;
int bfs(int st,int en)
{
    memset(vp,0,sizeof(vp));
    int ans=0x7f7f7f7f;
    que.push({st,0});
    while(!que.empty())
    {
        node last=que.front();
        que.pop();
        int last_x=last.x;
        int last_cost=last.num;
        vp[last_x]=1;
        if(last_x==en)
        {
            ans=min(ans,last_cost+tim[en]+tim[st]);
            continue;
        }
        for(auto i:point[last_x])
            for(auto j:line[i.first])
                if(vp[j]==0)
                    que.push({j,last_cost+(i.second+val[j][i.first])});
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>tim[i];
    for(int i=1;i<=n;i++)
    {
        cin>>len;
        for(int j=1;j<=len;j++)
        {
            int a,t;
            cin>>a>>t;
            line[i].push_back(a);
            point[a].push_back({i,t});
            val[a][i]=t;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int st,en;
        cin>>st>>en;
        cout<<bfs(st,en)<<'\n';
    }
    return 0;
}
