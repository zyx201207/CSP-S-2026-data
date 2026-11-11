#include<bits/stdc++.h>
#define int long long
#define ll (long long)
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans=0;
int vis[25];
int ssum=LLONG_MAX;
int maxx=-1e18;
int cnt=0;
int rtwo=0;
int rone=0;
void dfs(int cur,int num,int step)
{
    if(step==m)
    {
        ans=max(ans,num);
        return ;
    }
    if(step>m)return ;
    for(int i=cur+1;i<=n;i++)
    {
        dfs(i,num&a[i],step+1);
    }
}
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ssum=ssum&a[i];
        maxx=max(maxx,a[i]);
        if(a[i]==3 && cnt!=-1)cnt++;
        if(a[i]>3)cnt=-1;
        if(a[i]==2)rtwo++;
        if(a[i]==1)rone++;
    }
    if(n<=20)
    {
        dfs(0,LLONG_MAX,0);
        printf("%lld\n",ans);
        exit(0);
    }
    if(n==m)
    {
        printf("%lld\n",ssum);
        exit(0);
    }
    if(m==1)
    {
        printf("%lld\n",maxx);
        exit(0);
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)ans=max(ans,a[i]&a[j]);
            }
        }
        printf("%lld\n",ans);
        exit(0);
    }
    if(cnt!=-1)
    {
        if(cnt>=m)
        {
            printf("3\n");
        }
        else if(cnt+rtwo>=m)
        {
            printf("2\n");
        }
        else if(cnt+rone>=m)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        exit(0);
    }
    if(1)
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=ll(log2(a[i]+1));
        }
        sort(a+1,a+n+1,cmp);
        printf("%lld\n",a[m]);
        exit(0);
    }
    return 0;
}
