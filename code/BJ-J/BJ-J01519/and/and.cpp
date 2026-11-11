#include <bits/stdc++.h>
using namespace std;
long long n,m,a[300010];
long long ans=-1;
long long tmp[30];
map<long long,long long>mp;
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int id,int num,long long sum)
{
    if(num>m)return;
    if(id==n+1)
    {
        if(num==m)ans=max(ans,sum);
        return ;
    }

    if(sum==-1)
    {
        dfs(id+1,num+1,a[id]);
        dfs(id+1,num,sum);
    }
    else
    {
        dfs(id+1,num+1,sum&a[id]);
        dfs(id+1,num,sum);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20)
    {
        dfs(1,0,-1);
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        long long ma=-1e9;
        for(int i=1;i<=n;i++)ma=max(ma,a[i]);
        cout<<ma;
        return 0;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        long long sum=0;
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=n-1;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    int vis=0;
    for(int i=1;i<=n;i++)if(a[i]>4)vis=1;
    if(vis==0)
    {
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    vis=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=i-1)vis=1;
    if(vis==0)
    {
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    int flag=1;
    for(int i=0;i<=30;i++)mp[pow(2,i)-1]=1;
    for(int i=1;i<=n;i++)
        if(mp.count(a[i]))flag=0;
    if(flag==1)
    {
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++)ans&=a[i];
    cout<<ans;

    return 0;
}