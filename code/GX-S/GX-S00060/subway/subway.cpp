#include<bits/stdc++.h>
using namespace std;
#define int long long
struct jk{
    int a=0,t=0;
};
int c,n,m,d,q,sum=0;
int w[500005];
vector<jk> dt[505];
vector<jk> zt[500005];
int dis[505][505];
int dis2[505][505];
jk dui[505];
bool operator<(jk x,jk y)
{
    return x.t<y.t;
}
void push(jk x)
{
    dui[++dui[0].a]=x;
    int j=dui[0].a;
    while(j>1)
    {
        if(dui[j]<dui[j>>1])
        {
            swap(dui[j],dui[j>>1]);
        }
        else break;
        j>>=1;
    }
    return;
}
void pop()
{
    dui[1]=dui[dui[0].a];
    dui[0].a--;
    int j=1;
    while((j<<1)<=dui[0].a)
    {
        if(dui[j<<1]<dui[j] and ((j<<1|1)>dui[0].a || dui[j<<1]<dui[j<<1|1]))
        {
            swap(dui[j],dui[j<<1]);
            j<<=1;
        }
        else if((j<<1|1)<=dui[0].a and dui[j<<1|1]<dui[j])
        {
            swap(dui[j],dui[j<<1|1]);
            j=j<<1|1;
        }
        else break;
    }
    return;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            dt[i].push_back({a,t});
            zt[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=4e18;
            dis2[i][j]=4e18;
            if(i==j) dis[i][j]=0;
            if(i==j) dis2[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<dt[i].size();j++)
            {
                int to=dt[i][j].a,t1=dt[i][j].t;
                for(int k=0;k<zt[to].size();k++)
                {
                    int to2=zt[to][k].a,t2=zt[to][k].t;
                    dis2[i][to2]=min(dis[i][to2],t1+t2);
                }
            }
    }
    for(int i=1;i<=n;i++)
    {
        push({i,0});
        while(dui[0].a>0)
        {
            jk f=dui[1];
            pop();
            if(dis[i][f.a]<f.t) continue;
            for(int j=1;j<=n;j++)
            {
                if(dis[i][f.a]+dis2[f.a][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][f.a]+dis2[f.a][j];
                    push({j,dis[i][j]});
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y,sum=4e18;
        cin>>x>>y;
        for(int j=0;j<zt[x].size();j++)
        {
            int to=zt[x][j].a,t1=zt[x][j].t;
            for(int k=0;k<zt[y].size();k++)
            {
                int to2=zt[y][k].a,t2=zt[y][k].t;
                sum=min(sum,dis[to][to2]+t1+t2);
            }
        }
        cout<<sum+w[x]+w[y]<<"\n";
    }
    return 0;
}
