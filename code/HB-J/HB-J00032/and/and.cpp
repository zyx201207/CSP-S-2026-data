#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;

int n,m,maxn=-1;
int a[MAXN];
long long ans=0,asum;

void dfs(int step,long long s,int up)
{
    if(step==m+1)
    {
        ans=max(ans,s);
        return;
    }
    for(int i=up+1;i<=n;i++)
    {
        dfs(step+1,s&a[i],i);
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        asum=a[1];
        for(int i=1;i<=n;i++)
        {
            asum=asum&a[i];
        }
        cout<<asum;
        return 0;
    }
    //if(n<=2000)
    //{
        for(int i=1;i<=n;i++)
        {
            dfs(2,a[i],i);
        }
        cout<<ans;
    //}
    return 0;
}
