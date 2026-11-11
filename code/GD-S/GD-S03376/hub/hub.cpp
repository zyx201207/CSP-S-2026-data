#include<stdio.h>
const int N=2000005;
int idd,t,n,k,a,b,fir[N],num;
struct ss{int ed,nxt;}bia[N*2];
int fa[N][22],dep[N],cho[N],ans;
bool ff[N];int ft[N];
void dfs(int wh,int fas)
{
    dep[wh]=dep[fas]+1,fa[wh][0]=fas;
    for(int i=1;i<=21;i++)
    fa[wh][i]=fa[fa[wh][i-1]][i-1];
    for(int i=fir[wh];i;i=bia[i].nxt)
    if(bia[i].ed!=fas) dfs(bia[i].ed,wh);
}
void clear()
{
    for(int i=1;i<=n;i++)
    {
        fir[i]=dep[i]=ff[i]=0;
        for(int j=0;j<=21;j++)
        fa[i][j]=0;
    }num=0,ans=1e9;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int ask(int a,int b)
{
    if(dep[a]<dep[b]) a^=b^=a^=b;
    for(int i=21;i>=0;i--)
    if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
    if(a==b) return b;
    for(int i=21;i>=0;i--)
    if(fa[a][i]!=fa[b][i])
    a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
int fnd(int x){return x==ft[x]?x:ft[x]=fnd(ft[x]);}
bool check()
{
    for(int i=1;i<=n;i++) ft[i]=i;
    for(int i=1;i<=k;i++)
    for(int j=fir[cho[i]];j;j=bia[j].nxt)
    if(ff[bia[j].ed]) ft[fnd(cho[i])]=fnd(bia[j].ed);
    int cnt=1;
    for(int i=2;i<=k;i++)
    if(fnd(cho[i])!=fnd(cho[1])) cnt++;
    return cnt>2;
}
void sol(int wh)
{
    if(wh>k)
    {
        if(check()) return;int sum=0;
        for(int i=1;i<=n;i++)
        {
            int dq=1e9;
            for(int j=1;j<=k;j++)
            dq=min(dq,ask(cho[j],i));
            sum=max(sum,dq);
        }ans=min(ans,sum);return;
    }for(int i=1;i<=n;i++) if(!ff[i])
    ff[i]=1,cho[wh]=i,sol(wh+1),ff[i]=0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&idd,&t);while(t--)
    {
        scanf("%d%d",&n,&k);clear();
        for(int i=1;i<n;i++) scanf("%d%d",&a,&b),
        bia[++num].ed=b,bia[num].nxt=fir[a],fir[a]=num,
        bia[++num].ed=a,bia[num].nxt=fir[b],fir[b]=num;
        dfs(1,0);sol(1);printf("%d\n",ans);
    }
}