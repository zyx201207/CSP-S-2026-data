/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;//t[35],vis[35];
struct node{
    int v,c;
}dp[200005];
bool check(int x)
{
    long long q=(1<<31)-1;
    int y=(int)q;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(dp[i-1].v&a[i]<x)
        {
            dp[i].v=y%a[i];
            dp[i].c=1;
        }
        else
        {
            dp[i].v=a[i]&dp[i-1].v;
            dp[i].c=dp[i-1].c+1;
        }
        if(dp[i].c>=m)return 1;
    }
    return 0;
}
int main()
{
//    freopen("and.in","r",stdin);
 //   freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
     //   int x;
       // cin>>x;
      //  int l=1;
      //  while(x>0)
       // {
        //    if(x&1)
      //      {
        //        t[l]++;
          //  }
        //    x>>=1;
          //  l++;
        //}
    }
    int l=0,r=1<<30;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int vis[25];
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int x)
{
    if(x>n)
    {
        int cnt=0,y;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==1)
            {
                if(cnt==0)y=a[i];
                else y=y&a[i];
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans=max(ans,y);
        }
        return;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    if(n<=20)
    {
        dfs(1);
        cout<<ans;
    }
    else if(m==1)
    {

        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n)
    {

        int sum=a[1];
        for(int i=1;i<=n;i++)
        {
            sum=sum&a[i];
        }
        cout<<sum;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n-1)
    {

    }
    else
    {

        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=1;i<=m;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }

    return 0;
}

