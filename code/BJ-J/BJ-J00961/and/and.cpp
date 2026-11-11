#include <bits/stdc++.h>
using namespace std;
const long long N=200005;
const long long M=2005;
long long a[N],f[M][M];
long long n,m,ans;
void dfs(long long u,long long sum,long long cnt)
{
    if(u>n)
    {
        if(cnt==m)
        {
            ans=max(ans,sum);
        }
        return ;
    }
    dfs(u+1,sum,cnt);
    dfs(u+1,sum&a[u],cnt+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        dfs(1,(long long)(1<<31)-1,0);
        cout<<ans;
        return 0;
    }
    if(n<=2000)
    {
        if(m==1)
        {
            long long ans=0;
            for(long long i=1;i<=n;i++)
            {
                ans=max(ans,a[i]);
            }
            cout<<ans;
        }
        else if(m==n)
        {
            long long ans=a[1];
            for(long long i=2;i<=n;i++)
            {
                ans=ans&a[i];
            }
            cout<<ans;
        }
        else
        {
            long long ans=0;
            for(long long i=1;i<=n;i++)
            {
                for(long long j=i+1;j<=n;j++)
                {
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
        }
    }
    if(n>2000)
    {
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    return 0;
}
