#include<bits/stdc++.h>
using namespace std;
bool mark[1000010];
long long a[1000010];
long long now[1000010];
long long ans=-1;
long long n,m;
void dfs(long long x,long long step)
{
    if(step>m)
    {
        long long cnt=a[now[1]];
        for(int i=2;i<=m;i++)
        {
            cnt=cnt&a[now[i]];
        }
        ans=max(ans,cnt);
        return ;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(!mark[i])
        {
            mark[i]=1;
            now[step]=i;
            dfs(i,step+1);
            mark[i]=0;
        }
    }
}
long long my_pow(long long x,long long y)
{
    int cnt=1;
    while(y)
    {
        if(y%2==1)
        {
            cnt=cnt*x;
        }
        y/=2;
        x=x*x;
    }
    return cnt;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool ok=0;
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=1;j<=31;j++)
        {
            if(a[i]==my_pow(2,j))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        int ret=a[n];
        sort(a+1,a+1+n);
        for(int i=n-1,j=m-1;j>=1;i--,j--)
        {
            ret=ret&a[i];
        }
        cout<<ret;
        return 0;
    }
    dfs(0,1);
    cout<<ans;
    return 0;
}
