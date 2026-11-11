#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxx;
bool vis[N];
void dfs(int x,int y)
{
    if(x>n)
    {
        if(m==y)
        {
            int t=0xffffffff;
            for(int i=1;i<=n;i++)
            {
                if(vis[i])
                {
                    t&=a[i];
                }
            }
            maxx=max(maxx,t);
        }
        return;
    }
    dfs(x+1,y);
    vis[x]=1;
    dfs(x+1,y+1);
    vis[x]=0;
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
    if(m==1)
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
    }
    else if(n<=2000)
    {
        dfs(1,0);
        cout<<maxx;
    }
    else
    {
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
    }
    return 0;
}
