#include<cstdio>
#include<bitset>
#include<iostream>
using namespace std;

const int nn=1000006;
const int n2=nn<<1;
const int n04=105;

void Make(int,int);
int frst[nn],nxt[n2],go[n2],tot;

int n,K;

void work02();
int team[nn],dis[nn];

//void work04();
//void Clear04();
//
//void dfs1(int,int);
//int len[nn];
//
//bool Check(int);
//
//void dfs2(int,int,int);
//bitset<n04> f1[n04][n04],f2[n04][n04];

void work13();

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int qc,qt;
    scanf("%d%d",&qc,&qt);

    if(qc==13||qc==14)
    {
        while(qt--) work13();
    }

    if(qc<=3)
    {
        while(qt--) work02();
    }

//    while(qt--) work04();

    return 0;
}

void work02()
{
    scanf("%d%d",&n,&K);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        Make(x,y);
        Make(y,x);
    }

    int ans=n-K;

    for(int w=2;w<(1<<n+1);w+=2)
    {
        int cnt=0;
        for(int i=1;i<=n;i++) if(w&(1<<i)) cnt++;
        if(cnt!=K) continue;
        int tail=0;

        int jie1=w,jie2=0;
        for(int qw=1;qw<=n;qw++) if(jie1&(1<<qw))
        {
            int jie=tail;
            jie2++;
            team[++tail]=qw;
            jie1^=(1<<qw);
            for(int head=jie,u;head<=tail;head++)
            {
                u=team[head];
                for(int i=frst[u],v;i;i=nxt[i])
                {
                    v=go[i];
                    if(jie1&(1<<v)) team[++tail]=v,jie1^=(1<<v);
                }
            }
        }
        if(jie2>2) continue;

        for(int i=1;i<=n;i++) dis[i]=nn;
        for(int i=1;i<=tail;i++) dis[team[i]]=0;
        for(int head=1;head<=tail;head++)
        {
            int u=team[head];
            for(int i=frst[u],v;i;i=nxt[i])
            {
                v=go[i];
                if(dis[v]==nn) dis[v]=dis[u]+1,team[++tail]=v;
            }
        }

        ans=min(ans,dis[team[n]]);

//        printf("w=%d dis=%d\n",w,dis[team[n]]);//
    }

    printf("%d\n",ans);

    for(int i=1;i<=n;i++) frst[i]=0;tot=0;

    return;
}

//void work04()
//{
//    scanf("%d%d",&n,&K);
//    for(int i=1,x,y;i<n;i++)
//    {
//        scanf("%d%d",&x,&y);
//        Make(x,y);
//        Make(y,x);
//    }
//
//    if(n<=K){puts("0");return Clear04()};
//
//    dfs1(1,0);
//
//    int left=1,right=n-K+1,middle,ans=n-K;
//    while(left<=right)
//    {
//        middle=left+right>>1;
//        if(Check(middle)) ans=middle,right=middle-1;
//        else left=middle+1;
//    }
//
//    printf("%d\n",ans);
//
//    return Clear04();
//}
//void Clear04();
//
//void dfs1(int u,int father)
//{
//    for(int i=frst[u],v;i;i=nxt[i])
//    {
//        v=go[i];
//        if(v==father) continue;
//        dfs1(v,u);
//        len[u]=max(len[u],len[v]);
//    }
//    len[u]++;
//    return;
//}
//bool Check(int x)
//{
//    dfs2(1,0,x);
//
//    bool res=0;
//    for(int i=0;i<=x;i++) if(f2[1]) return 1;
//
//    return 0;
//}
//
//void dfs2(int u,int father,int op)
//{
//    for(int i=0;i<=len[u];i++)
//    {
//        for(int j=0;j<=K;j++) f1[u][i].reset(),f2[u][j].reset();
//    }
//
//    for(int i=frst[u],v;i;i=nxt[i])
//    {
//        v=go[i];
//        if(v==father) continue;
//        dfs2(v,u,op);
//    }
//
//    f1[u][0][0]=1,f2[u][0][1]=1;
//    bitset<n04> g1[n04],g2[n04];
//
//    for(int i=frst[u],v;i;i=nxt[i])
//    {
//        v=go[i];
//        if(v==father) continue;
//    }
//
//
//
//    return;
//}

void work13()
{
    scanf("%d%d",&n,&K);
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y);

    if(K>=n){puts("0");return;}

    int jie1=n>>1;
    int jie2=jie1+2-K;

    int ans13=jie2+3>>2;

    printf("%d\n",ans13);

    return;
}


void Make(int x,int y)
{
    nxt[++tot]=frst[x];frst[x]=tot;go[tot]=y;
}
