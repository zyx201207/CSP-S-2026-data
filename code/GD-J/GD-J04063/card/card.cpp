#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long cnt[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(long long i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }

    for(int i = 1;i <= n;i ++)
    {
        vector<long long> x;
        for(int j = n - i;j <= n;j ++)
        {
            for(int k = 1;k <= x.size();k ++)
            {
                if(x[k] == a[j])
                {
                    for(int l = k;l <= x.size();l ++)
                    {
                        x[l] = -1;
                    }
                    break;
                }
            }
            x.push_back(a[j]);
        }

        for(int j = 1;j <= x.size();j ++)
        {
            if(x[j] != -1)
            {
                cnt[x[j]] ++;
            }
        }
    }

    for(int i = 1;i <= m;i ++)
    {
        cout << cnt[i] << " ";
    }

    return 0;
}
