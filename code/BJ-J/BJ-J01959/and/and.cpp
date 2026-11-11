#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool vis[200005];
long long ans=-1;
long long ans2=-1;
long long ans3=0;
long long ans4=0;
long long ans5=0;
void dfs (int cur,int cnt)
{
    if (cnt==m)
    {
        long long s=0;
        bool f=0;
        for (int i=1;i<=n;i++)
        {
            if (vis[i]==1)
            {
                if (f==0)
                {
                    s=a[i];
                    f=1;
                }
                else
                {
                    s=s&a[i];
                }
            }
        }
        ans=max(ans,s);
        return ;
    }
    if (cur>n)
    {
        return ;
    }
    vis[cur]=1;
    dfs (cur+1,cnt+1);
    vis[cur]=0;
    dfs (cur+1,cnt);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n<=20)
    {
        dfs (1,0);
        cout<<ans;
    }
    else if (n>20&&n<=2000)
    {
        if (m==1)
        {
            for (int i=1;i<=n;i++)
            {
                ans2=max(ans2,a[i]);
            }
            cout<<ans2;
        }
        if (m==n)
        {
            ans3=a[1];
            for (int i=2;i<=n;i++)
            {
                ans3=ans3&a[i];
            }
            cout<<ans3;
        }
        if (m==2)
        {
            bool f2=0;
            for (int i=1;i<=n;i++)
            {
                for (int j=i+1;j<=n;j++)
                {
                    if (f2==0)
                    {
                        ans4=a[i]&a[j];
                        f2=1;
                    }
                    else
                    {
                        ans4=max(ans4,a[i]&a[j]);
                    }
                }
            }
            cout<<ans4;
        }
    }
    else
    {
        bool fj=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]!=i-1)
            {
                fj=1;
                break;
            }
        }
        if (fj==1)
        {
            sort (a+1,a+n+1,greater<int>());
            cout<<a[m];
        }
        if (fj==0)
        {
            sort (a+1,a+n+1,greater<int>());
            ans5=a[1];
            for (int i=2;i<=m;i++)
            {
                ans5=ans5&a[i];
            }
            cout<<ans5;
        }
    }
    return 0;
}
