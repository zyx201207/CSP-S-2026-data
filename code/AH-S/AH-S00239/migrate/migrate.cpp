#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2000010];
long long cnt;
long long now=0;
void dfs(long long x,long long y,long long step)
{
    if(step>=cnt)
    {
        return ;
    }
    if(x==y)
    {
        cnt=min(cnt,step);
        return ;
    }
    for(long long i=x+1;i<=n;i++)
    {
        if(abs(a[i]-a[x])<=d)
        {
            dfs(i,y,step+1);
        }
    }
}
void dfs1(long long x,long long y,long long step)
{
    if(step>cnt)
    {
        return ;
    }
    //cout<<x<<' '<<y<<' '<<step<<'\n';
    if(x==y)
    {
        now+=(step==cnt);
        return ;
    }
    for(long long i=x+1;i<=n;i++)
    {
        if(abs(a[i]-a[x])<=d)
        {
            dfs1(i,y,step+1);
        }
    }
}
bool check(long long s,long long e)
{
    now=0;
    cnt=1e18;
    dfs(s,e,0);
    dfs1(s,e,0);
    //cout<<cnt<<' '<<now<<'\n';
    if(now==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        //cout<<d<<'\n';
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long ans=0;
        for(long long u=1;u<=n;u++)
        {
            for(long long v=u+1;v<=n;v++)
            {
                if(check(u,v))
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
