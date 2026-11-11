#include<cstring>
#include<iostream>
#include<cstdio>
#include<deque>
#define int long long
using namespace std;
const int N=500+10,M=500000+10,D=20+5;
struct edg
{
    int to,len,pre;
    edg(){};
    edg(int t,int l,int p):to(t),len(l),pre(p){};
}edge[N*N];
int c,n,m,d,q;
int cost[M];
int head[N],cnt=0;
int dis[N];
int lt[N];
bool inq[N];
deque<int>dque;
pair<int,int> dists[N][N]={};//id len
int dis2[N][N];
pair<int,int> subways[M][D];//idx len
void adde(int st,int ed,int len)
{
    dis2[st][ed]=min(dis2[st][ed],len);
    if(len>dists[st][ed].second)
        return;
    if(dists[st][ed].second>=0x3f3f3f3f)
    {
        edge[++cnt]=edg(ed,len,head[st]);
        head[st]=cnt;
        dists[st][ed].first=cnt;
    }
    else
        edge[dists[st][ed].first].len=len;
    dists[st][ed].second=len;
}
void floyd()
{
    for(int i=1;i<=n;i++)
    {
        dis2[i][i]=0;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(i!=j&&i!=k&&j!=k&&dis2[i][j]<0x3f3f3f3f&&dis2[j][k]<0x3f3f3f3f)
                    dis2[i][k]=min(dis2[i][k],dis2[i][j]+dis2[j][k]);
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%lld ",dis2[i][j]);
        printf("\n");
    }*/
}
int spfa(int st,int ed)
{
    int res=0x7fffffff;
    for(int i=1;i<=subways[st][0].second;i++)
        for(int j=1;j<=subways[ed][0].second;j++)
        {
            //cout<<subways[ed][j].second<<" "<<subways[st][i].second<<" "<<dis2[subways[st][i].first][subways[ed][j].first]<<endl;
            res=min(res,
                    subways[ed][j].second+subways[st][i].second+dis2[subways[st][i].first][subways[ed][j].first]);
        }
    return res+cost[st]+cost[ed];
}
/*int spfa(int st,int ed)
{
    int res=0x7fffffff;
    memset(dis,0x3f,sizeof(dis));
    memset(lt,0,sizeof(lt));
    memset(inq,0,sizeof(inq));
    dque.clear();
    for(int i=1;i<=subways[st][0].second;i++)
    {
        dis[subways[st][i].first]=cost[st]+cost[ed]+subways[st][i].second;
        dque.push_back(subways[st][i].first);
        inq[subways[st][i].first]=true;
    }
    for(int i=1;i<=subways[ed][0].second;i++)
        lt[subways[ed][i].first]=subways[ed][i].second;
    while(!dque.empty())
    {
        int temp=dque.front();
        dque.pop_front();
        inq[temp]=false;
        if(lt[temp])
            res=min(res,dis[temp]+lt[temp]);
        for(int i=head[temp],to,len;i;i=edge[i].pre)
        {
            to=edge[i].to;
            len=edge[i].len;
            if(dis[to]>dis[temp]+len)
            {
                dis[to]=dis[temp]+len;
                if(!inq[to])
                {
                    if(dis[dque.front()]>dis[to])
                        dque.push_front(to);
                    else
                        dque.push_back(to);
                    inq[to]=true;
                }
            }
        }
    }
    return res;
}*/
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dists,0x3f,sizeof(dists));
    memset(dis2,0x3f,sizeof(dis2));
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&cost[i]);
    for(int i=1,temp;i<=n;i++)
    {
        scanf("%lld",&temp);
        for(int j=1,su,le;j<=temp;j++)
        {
            scanf("%lld%lld",&su,&le);
            subways[su][++subways[su][0].second]=make_pair(i,le);
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<subways[i][0].second;j++)
            for(int k=j+1;k<=subways[i][0].second;k++)
            {
                //cout<<i<<" "<<subways[i][j].first<<" "<<subways[i][k].first<<" "<<subways[i][j].second+subways[i][k].second<<endl;
                adde(subways[i][j].first,subways[i][k].first,subways[i][j].second+subways[i][k].second);
                adde(subways[i][k].first,subways[i][j].first,subways[i][j].second+subways[i][k].second);
            }
    floyd();
    for(int st,ed;q--;)
    {
        scanf("%lld%lld",&st,&ed);
        printf("%lld\n",spfa(st,ed));
    }
    return 0;
}
