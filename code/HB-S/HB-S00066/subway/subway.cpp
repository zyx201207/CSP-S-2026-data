//last :(
//last :(
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int t1[505];
int t2[505][200005];
int x[100005],y[100005];
vector<int>st[200005];
vector<vector<int>>e;
int idxout=0,idxtran=0;
void add(int u,int v,int len)
{
    e[u][v]=len;
    e[v][u]=len;
}
int outid[200005];
int calc(int,int,int);
void input()
{
    cin>>c>>n>>m>>d>>q;
    idxout=m;
    idxtran=2*m;
    for(int i=1;i<=m;i++)
        cin>>t1[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int lastop;
        for(int j=1;j<=k;j++)
        {
            int now,time2;
            cin>>now>>time2;
            st[now].push_back(i);
            add(now,m+now,t2[i][now]+t1[now]);
            add(now,m+now,t2[i][now]+t1[now]);
            t2[i][now]=time2;
            if(j>1)
                add(lastop,now,0);
            if(st[now].size()>1)
            {
                for(auto k:st[now])
                {
                    add(now,2*m+now,t2[k][now]+t2[i][now]);
                    add(now,m+now,t2[k][now]+t1[now]);
                }
            }
            lastop=now;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        cout<<calc(m+x[i],m+y[i],0);
    }
}
vector<vector<int>>dis;
vector<vector<bool>>vis;
int calc(int start,int endd,int step)
{
    if(start==endd)return step;
    for(int i=0;i<dis[start].size();i++)
    {
        if(dis[start][i]!=-1&&!vis[start][i])
        {
            vis[start][i]=1;
            return calc(i,endd,step+dis[start][i]);
            vis[start][i]=0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    e.resize(200005);
    for(int j=0;j<200005;j++)
    {
        e[j].resize(200005);
        for(int i=0;i<200005;i++)
        {
            e[j][i]=-1;
            if(i==j)e[i][i]=0;
        }
    }
    for(int j=0;j<200005;j++)
    {
        dis[j].resize(200005);
        for(int i=0;i<200005;i++)
        {
            dis[j][i]=-1;
            if(i==j)dis[i][j]=0;
        }
    }
    for(int j=0;j<200005;j++)
    {
        vis[j].resize(200005);
        for(int i=0;i<200005;i++)
        {
            vis[j][i]=-1;
            if(i==j)vis[i][j]=0;
        }
    }
    input();
    return 0;
    // :(
}
