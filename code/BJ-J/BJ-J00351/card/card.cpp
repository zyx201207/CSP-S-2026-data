#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long lst[300005],ans[300005],to[500005],val[500005],in[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=n;i>=1;i--)
    {
        if (lst[a[i]]!=0)
        {
            to[i]=lst[a[i]];
            val[i]=-1;
        }
        else
        {
            to[i]=i+1;
            val[i]=a[i];
        }
        lst[a[i]]=i;
        // cout << to[i] << ' ' << val[i] << endl;
    }
    for (int i=1;i<=n;i++)
    {
        in[i]++;
        in[to[i]]+=in[i];
    }
    for (int i=1;i<=n;i++)
    {
        if (val[i]==-1) continue;
        ans[val[i]]+=in[i];
    }
    for (int i=1;i<=m;i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}