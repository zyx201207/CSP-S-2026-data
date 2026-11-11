#include <bits/stdc++.h>
using namespace std;
int ans,cnt;
int n,m;
int a[200100];
bool vis[100100];
bool f;
void dfs(int k)
{
    if (k>m)
    {
        ans=max(ans,cnt);
        //cout<<cnt<<endl;
        return ;
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            int mo=cnt;
            vis[i]=1;
            if (!f)
            {
                if (cnt==0)
                {
                    cnt=a[i];
                    f=1;
                }
            }
            else cnt&=a[i];
            dfs(k+1);
            vis[i]=0;
            cnt=mo;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=20)
    {
        dfs(1);
        cout<<ans;
    }
    else if(m==1)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n)
    {
        int ans=a[1];
        for (int i=2;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
