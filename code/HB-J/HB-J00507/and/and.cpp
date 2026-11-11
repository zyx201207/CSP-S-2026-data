#include<bits/stdc++.h>
using namespace std;
int a[200010],ans;
int n,m;
void dfs(int s,int sum,int l)
{
    if(s==m)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=l+1;i<=n;i++)
    {
        dfs(s+1,sum&a[i],i);
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<100||m==2)
    {
        for(int i=1;i<=n;i++)dfs(1,a[i],i);
        cout<<ans;
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        cout<<ans;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
    }
    else if(m==4)
    {
        sort(a+1,a+n+1);
        ans=3;
        for(int i=n;i>n-m;i--)ans&=a[i];
        cout<<ans;
    }
    else
    {
        sort(a+1,a+n+1);
        ans=3;
        for(int i=n;i>n-m;i--)ans&=a[i];
        cout<<ans;
    }
    return 0;
}
