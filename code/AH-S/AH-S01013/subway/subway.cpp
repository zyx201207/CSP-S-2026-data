#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const ll M=5e5+10;
const ll N=510;
const ll Max=1e18;

ll w[M];
struct Node{
    ll v,wei;
};
ll lian[N][N];
vector<Node> pos[M];
ll c,n,m,d,q;

vector<Node> pos2[N];

struct cmp{
    bool operator()(pll x,pll y)
    {
        return x.second>y.second;
    }
};

priority_queue<pll,vector<pll>,cmp> que;
bool vis[N]={0};

void qiu(ll i)
{
    while(!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    que.push({i,0});
    lian[i][i]=0;
    while(!que.empty())
    {
        ll v3=que.top().first,wei3=que.top().second;
        que.pop();
        if(vis[v3]) continue;
        lian[i][v3]=min(wei3,lian[i][v3]);
        vis[v3]=1;
        for(Node v4:pos2[v3])
        {
            que.push({v4.v,lian[i][v3]+v4.wei});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(ll i=0;i<N;i++)
        for(ll j=0;j<N;j++)
        lian[i][j]=Max;

    for(ll i=1;i<=m;i++) cin>>w[i];


    for(ll i=1;i<=n;i++)
    {
        ll k;cin>>k;
        for(ll j=1;j<=k;j++)
        {
            ll aj,tj;cin>>aj>>tj;
            Node x;
            x.v=i;x.wei=tj;
            pos[aj].push_back(x);
        }
    }

    for(ll i=1;i<=m;i++)
    {
        for(auto it1=pos[i].begin();it1!=pos[i].end();it1++)
        {
            Node x1=*it1;
            ll v1=x1.v,wei1=x1.wei;
            for(auto it2=it1;it2!=pos[i].end();it2++)
            {
                if(it1==it2) continue;
                Node x2=*it2;
                ll v2=x2.v,wei2=x2.wei;
                lian[v2][v1]=lian[v1][v2]=min(lian[v1][v2],wei1+wei2);//cout<<wei1+wei2<<endl;
            }
        }
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(lian[i][j]!=Max)
            {
                Node x;
                x.v=j;x.wei=lian[i][j];
                pos2[i].push_back(x);
            }
        }
    }

    //for(ll i=1;i<=n;i++)        for(ll j=1;j<=n;j++)        cout<<i<<"and"<<j<<":"<<lian[i][j]<<endl;


    for(ll i=1;i<=n;i++) qiu(i);

    for(ll i=1;i<=q;i++)
    {
        ll x,y;cin>>x>>y;
        ll ans=Max;
        for(Node n1:pos[x])
        {
            ll ans1=n1.v,weii1=n1.wei;
            for(Node n2:pos[y])
            {
                ll ans2=n2.v,weii2=n2.wei;
                ans=min(ans,lian[ans1][ans2]+weii1+weii2);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }

    //for(ll i=1;i<=n;i++)        for(ll j=1;j<=n;j++)        cout<<i<<"and"<<j<<":"<<lian[i][j]<<endl;

    return 0;
}
