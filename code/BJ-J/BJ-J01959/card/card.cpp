#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool vis[300005];
long long h[300005];
stack<long long> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool f=0;
    for (int i=1;i<n;i++)
    {
        if (a[i]>a[i+1])
        {
            f=1;
            break;
        }
    }
    if (f==1)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                vis[j]=0;
            }
            for (int j=i;j<=n;j++)
            {
                if (vis[a[j]]==1)
                {
                    while (1)
                    {
                        if (s.top()==a[j])
                        {
                            vis[s.top()]=0;
                            s.pop();
                            break;
                        }
                        else
                        {
                            vis[s.top()]=0;
                            s.pop();
                        }
                        if (s.empty())
                        {
                            break;
                        }
                    }
                    s.push(a[j]);
                    vis[a[j]]=1;
                }
                else
                {
                    s.push(a[j]);
                    vis[a[j]]=1;
                }
            }
            while (!s.empty())
            {
                h[s.top()]++;
                s.pop();
            }
        }
        for (int i=1;i<=m;i++)
        {
            cout<<h[i]<<" ";
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                vis[j]=0;
            }
            for (int j=i;j<=n;j++)
            {
                vis[a[j]]=1;
            }
            for (int j=1;j<=m;j++)
            {
                h[j]+=vis[j];
            }
        }
        for (int i=1;i<=m;i++)
        {
            cout<<h[i]<<" ";
        }
    }
    return 0;
}
