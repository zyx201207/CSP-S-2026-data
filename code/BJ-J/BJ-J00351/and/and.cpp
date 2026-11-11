#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans,cnt;
bool vis[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=29;i>=0;i--)
    {
        cnt=0;
        for (int j=1;j<=n;j++)
        {
            if (vis[j]) continue;
            if (a[j]&(1<<i)) cnt++;
        }
        if (cnt>=m)
        {
            ans+=(1<<i);
            for (int j=1;j<=n;j++)
            {
                if ((a[j]&(1<<i))==0) vis[j]=true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}