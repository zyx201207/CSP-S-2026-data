#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y)
{
    return x>y;
}
bool check()
{
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]&a[i+1]!=min(a[i],a[i+1]));
        return false;
    }
    return true;
}
bool vis[50];
int ans1=-1,cnt1=-1,pos1=-1;
void dfs(int step)
{

    if(step>m)
    {
        for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            cnt1=a[i];
            pos1=i+1;
            break;
        }
    }
        for(int i=pos1;i<=n;i++)
        {
            if(vis[i])
                cnt1=cnt1&a[i];
            //cout<<cnt<<" ";
        }
        if(cnt1>=ans1)
            ans1=cnt1;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=true;
        dfs(step+1);
        vis[i]=false;
        dfs(step+1);
    }
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
    if(check())
    {
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }
    if(n==m)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
        return 0;
    }
    if(m==2)
    {
        int ans=-1;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>ans)
                    ans=a[i]&a[j];
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        int cnt;
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(i==1)
                cnt=a[2];
            else
                cnt=a[1];
            for(int j=1;j<=n&&(j!=i);j++)
            {
                cnt=cnt&a[j];
            }
            if(cnt>ans)
                ans=cnt;
        }
        cout<<ans;
        return 0;
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    cout<<endl;
    cout<<ans1;
    return 0;
}
