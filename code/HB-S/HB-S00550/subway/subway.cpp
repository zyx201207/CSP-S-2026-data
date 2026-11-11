#include <bits/stdc++.h>
#define int long long
#define N 505

using namespace std;
int c,n,m,d,q,w[500005];
struct node
{
    int a,t;
};


struct ask
{
    int idx,x,y;
}qq[100005];

struct result
{
    int idx;
    vector<pair<int,int> >ress;
};



vector<node>a[N];
int dis[N][N];//两条铁路之间的距离


void Bronya()//build a graph
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=i==j?0:1e18;

            
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)//枚举路线
        {
            int u=0,v=0;//双指针枚举两条路线的第uv个节点是否相同
            while(u<=a[i].size() && v<=a[j].size())
            {
                if(a[i][u].a<a[j][v].a)u++;
                else if(a[i][u].a>a[j][v].a)v++;
                else if(a[i][u].a==a[j][v].a)
                {
                    // printf("a[%lld][%lld].a=%lld,a[%lld][%lld].a=%lld\n",j,v,a[j][v].a,i,u,a[i][u].a);
                    // printf("a[%lld][%lld].t=%lld,a[%lld][%lld].t=%lld\n",j,v,a[j][v].t,i,u,a[i][u].t);
                    dis[i][j]=min(a[j][v].t+a[i][u].t,dis[i][j]);//两条铁路相通，转换代价为两路线重合节点转换的最小值
                    u++,v++;
                }
            }
            dis[j][i]=dis[i][j];
        }
    }
}

void Elysia()//actual Floyd
{
    for(int mid=1;mid<=n;mid++)
    {
        for(int u=1;u<=n;u++)
        {
            if(u==mid)continue;
            for(int v=1;v<=n;v++)
            {
                if(v==u || v==mid)continue;
                dis[u][v]=min(dis[u][v],dis[u][mid]+dis[mid][v]);
            }
        }
    }
}

int mybs(int ty,int tar)
{
    int l=1,r=q,res=-1;
    if(ty==1)//按照x查找最小的一个点
    {
        while(l<=r)
        {
            int mid=l+r>>1;
            if(qq[mid].x<tar)l=mid+1;
            else 
            {
                res=mid;
                r=mid-1;
            }
        }
        return res;
    }
    else 
    {
        while(l<=r)
        {
            int mid=l+r>>1;
            if(qq[mid].y<tar)l=mid+1;
            else 
            {
                res=mid;
                r=mid-1;
            }
            
        }
        return res;
    }
    
}
result inl[100005],outl[100005];

void init()
{
    //先找入点
    sort(qq+1,qq+1+q,[](ask a,ask b){return a.x<b.x;});
    
    for(int line=1;line<=n;line++)//遍历铁路
    {
        for(node nd:a[line])//每个节点
        {
            int fd=mybs(1,nd.a);
            if(fd!=-1)//在询问中查找是否需要当前节点信息
            {
                for(int lll=fd;lll<=q;lll++)
                {
                    if(qq[lll].x!=nd.a)break;
                    inl[qq[lll].idx].ress.push_back(make_pair(line,nd.t));
                }
                
            }
        }
    }
    //再找出点
    sort(qq+1,qq+1+q,[](ask a,ask b){return a.y<b.y;});
    for(int line=1;line<=n;line++)//遍历铁路
    {
        for(node nd:a[line])//每个节点
        {
            int fd=mybs(0,nd.a);
            if(fd!=-1)//在询问中查找是否需要当前节点信息
            {
                for(int lll=fd;lll<=q;lll++)
                {
                    if(qq[lll].y!=nd.a)break;
                    outl[qq[lll].idx].ress.push_back(make_pair(line,nd.t));
                }
            }
        }
    }
    sort(qq+1,qq+1+q,[](ask a,ask b){return a.idx<b.idx;});
}



int Cyrene(int num)
{
    int minn=1e18,u=qq[num].x,v=qq[num].y;
    for(pair<int,int> i:inl[num].ress)
    {
        for(pair<int,int> j:outl[num].ress)
        {
            minn=min(minn,i.second+dis[i.first][j.first]+j.second);
        }
    }
    return minn+w[u]+w[v];
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,aa,tt;j<=k;j++)
        {
            cin>>aa>>tt;
            a[i].push_back({aa,tt});
        }
        sort(a[i].begin(),a[i].end(),[](node x,node y){return x.a<y.a;});
    }
    Bronya();
    Elysia();
    for(int i=1;i<=q;i++)
    {
        cin>>qq[i].x>>qq[i].y;
        qq[i].idx=i;
    }
    init();
    for(int i=1;i<=q;i++)cout<<Cyrene(i)<<"\n";
    
    return 0;
}