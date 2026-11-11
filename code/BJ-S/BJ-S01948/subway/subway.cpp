#include <bits/stdc++.h>
#define int long long
using namespace std;

int w[100005],v[100005];
vector <int> v1[100005];
int maxn = 0;

void dfs(int step,int last,int time)
{
    if (step == last)
    {
        maxn = max(maxn,time);
    }
    for (int i = 0; i < v1[step].size(); i++)
    {
        dfs(step + 1,v1[step][i],time + v[i]);
    }
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int q;
        cin >> q;
        int last = 0;
        for (int j = 1; j <= q; j++)
        {
            int l,r;
            cin >> l >> r;
            v[j] = r;
            if (j > 1)
            {
                v1[last].push_back(l);
                v1[l].push_back(last);
            }

        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l,r;
        cin >> l >> r;
        dfs(l,r,0);
        cout << maxn + w[l] + w[r];
    }
    return 0;
}
