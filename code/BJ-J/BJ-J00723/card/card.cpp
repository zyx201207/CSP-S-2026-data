#include <bits/stdc++.h>
using namespace std;
int n,m,vis[500005],a[500005],ans[500005];
queue<int>q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j = i;j<=n;j++)
        {
            q.push(a[j]);
            if(vis[a[j]] != 0)
            {
                for(int k = 0;k<vis[a[j]];k++)
                {
                    int x = q.front();
                    q.pop();
                    q.push(x);
                }
                for(int k = vis[a[j]];k<q.size();k++)
                {
                    q.pop();
                }
            }
            else
            {
                vis[a[j]] = q.size();
            }
        }
        for(int j = 0;j<q.size();j++)
        {
            cout << q.front() << " ";
            ans[q.front()]++;
            q.pop();
        }
        cout << endl;
    }
    for(int i = 1;i<=m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}