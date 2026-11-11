#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxx=-999999999,flag,fflag,sum,ffflag;
bool vis[200005];
void dfs(int depth,int cnt,int wz)
{
    if(depth==m+1)
    {
        maxx=max(maxx,cnt);
        return;
    }
    for(int i=wz+1;i<=n;i++)
    {
        if(depth==1)cnt=a[i];
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(depth+1,cnt&a[i],i);
            vis[i]=0;
        }
    }
}
signed main(void)
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=1;
        for(int j=1;j<=30;j++)
        {
            x=x*2;
            if(a[i]==x-1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)fflag=1;
    }
    if(fflag==0)
    {
        sort(a+1,a+1+n,greater<int>());
        cout<<a[m];
        return 0;
    }
    int x=1;
    for(int i=1;i<=30;i++)
    {
        x=x*2;
        if(n==x)
        {
            ffflag=1;
            break;
        }
    }
    if(ffflag==1)
    {
        int fffflag=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=i-1)
            {
                fffflag=1;
                break;
            }
        }
        if(fffflag==0)
        {
            sum=a[n];
            for(int i=n;i>=n-m+1;i--)sum=sum&a[i];
            cout<<sum;
            return 0;
        }
    }
    dfs(1,a[1],0);
    cout<<maxx;
    return 0;
}
