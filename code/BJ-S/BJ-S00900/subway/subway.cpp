#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int M=5e5+10;
int c,n,m,d,q,w[M],tl[M][20],dis[M];//time of go to line i
struct node
{
    int x,l;
    bool operator > (node o)
   {
        return o.l>l;
    }
};
vector <node> g[M];
void dij(int x)
{
    memset(dis,0x3f,sizeof(dis));
    dis[x]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({x,0});
    while(!q.empty())
    {
        int t=q.top().first;q.pop();
       for(node u:g[t])
        {
            int t1=u.x,t2=t;
            if(dis[t1]>dis[t2]+u.l)
            {
                dis[t1]=dis[t2]+u.l;
                q.push({u.x,u.l});
            }
        }
    }
}
struct answer
{
    int l,r,id;
};
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        int x,w;
        vector<int> tp;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>w;
            tl[x][i]=w;
            tp.push_back(x);
        }
        for(int k=0;k<tp.size();k++)
        {
            for(int j=0;j<tp.size();j++)
            {
                if(k==j)
                    continue;
                int w1=tl[tp[k]][i]+tl[tp[j]][i];
                g[tp[k]].push_back({tp[j],w1});
            }
        }
    }
    vector<answer> ask;
    vector<int> st;
    vector<int> ansn(q+1);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        ask.push_back({x,y,i});
        st.push_back(x);
        //cout<<dij(x,y)+w[x]+w[y]<<"\n";
    }
    int i=0;
    for(int sta:st)
    {
        dij(sta);
        while(ask[i].l==sta)
        {
            ansn[ask[i].id]=dis[ask[i].r]+w[sta]+w[ask[i].r];
            //cout<<dis[ask[i].r]<<' ';
            i++;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ansn[i]<<"\n";
    }
    return 0;
}
