#include <bits/stdc++.h>
using namespace std;
long long a[200010];
unsigned long long mx=-1e9;
int n,m;
bool f[200010];
void dfs(int i,int cnt,unsigned long long sum)
{
    if(i==n+1)
    {
        if(cnt==m)mx=max(mx,sum);
        return ;
    }
    for(int j=1;j <= n;j++)
    {
        if(f[j]==0)
        {
            dfs(i+1,cnt,sum);
            f[j]=1;
            dfs(i+1,cnt+1,sum&a[j]);
            f[j]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
    unsigned long long s=1;
    unsigned long long mul=1;
    for(int i=0;i <= 30;i++)
    {
        mul*=2;
        s+=mul;
    }
    dfs(1,0,s);
    printf("%lld",mx);
    return 0;
}

