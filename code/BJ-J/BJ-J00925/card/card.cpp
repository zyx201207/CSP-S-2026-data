#include <bits/stdc++.h>
using namespace std;

int vis[300005],a[500005],n,m,cnt[300005];
stack<int> s,ep;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int r=1;r<=n;r++)
    {
        memset(vis,0,sizeof(vis));
        s=ep;
        for(int i=r;i<=n;i++)
        {
            if(vis[a[i]]>0)
            {
                while(!s.empty()&&vis[a[i]]>0)
                {
                    if(s.top()==a[i])
                    {
                        vis[a[i]]--;
                        s.pop();
                        break;
                    }
                    vis[s.top()]--;
                    s.pop();
                }
            }
            s.push(a[i]);
            vis[a[i]]++;
        }
        for(int i=1;i<=m;i++) cnt[i]+=vis[i];
    }
    for(int i=1;i<=m;i++) cout << cnt[i] << ' ';
    return 0;
}
