#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[200005];
bool v[200005];
void dfs(long long depth,long long sum)
{
    if(depth==m)
    {
        ans=max(ans,sum);
        return ;
    }
    for(long long i=1;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            dfs(depth+1,sum&a[i]);
            v[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(long long i=1;i<=n;i++)
    {
        v[i]=1;
        dfs(1,a[i]);
        v[i]=0;
    }
    printf("%lld",ans);
    return 0;
}
