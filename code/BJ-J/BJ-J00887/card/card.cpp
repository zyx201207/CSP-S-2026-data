#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],f[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        int l=i;
        stack<int>sta;
        memset(vis,0,sizeof(vis));
        while (l<=n)
        {
            if (!vis[a[l]])
            {
                sta.push(a[l]);
                vis[a[l]]=1;
            }
            else
            {
                while (sta.top()!=a[l])
                {
                    vis[sta.top()]=0;
                    sta.pop();
                }
            }
            l++;
        }
        while (!sta.empty())
        {
            f[sta.top()]++;
            sta.pop();
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<f[i]<<" ";
    }
    return 0;
}
