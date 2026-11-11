#include <bits/stdc++.h>
using namespace std;
vector<long long> e[31];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m,a[200001],x[31] = {},maxn = 0,max1 = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        for (int j = 0;a[i] >= (1 << j) && j <= 30;j++)
        {
            if (a[i] & (1 << j))
            {
                x[j]++;
                e[j].push_back(a[i]);
                max1 = max(max1,(long long)j);
            }
        }
    }
    for (int i = max1;i >= 0;i--)
    {
        if (x[i] >= m)
        {
            maxn += (1 << i);
            max1 = 0;
            memset(x,0,sizeof(x));
            for (int j = 0;j < i;j++)
            {
                e[j].clear();
            }
            for (auto u : e[i])
            {
                for (int j = i - 1;j >= 0;j--)
                {
                    if (u & (1 << j))
                    {
                        x[j]++;
                        e[j].push_back(u);
                        max1 = max(max1,(long long)j);
                    }
                }
            }
            i = min((long long)i,max1 + 1);
        }
    }
    cout << maxn << endl;
    return 0;
}