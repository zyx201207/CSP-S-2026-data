#include <bits/stdc++.h>
using namespace std;

vector<long long> mp[200010];

struct node
{
    long long xx,sum,line;
};

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int w[1000] = {},t[1000][1000] = {},l[1000] = {};
    long long c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        int k;
        long long a[1000] = {};

        cin >> k;
        for(int j = 1;j <= k;j ++)
        {
            cin >> a[j];
            cin >> t[i][a[j]];
            l[a[j]] = i;
        }
        for(int j = 1;j <= k;j ++)
        {
            if(j == 1)
            {
                mp[a[j]].push_back(a[j + 1]);
            }
            else if(j == n)
            {
                mp[a[j]].push_back(a[j - 1]);
            }
            else
            {
                mp[a[j]].push_back(a[j + 1]);
                mp[a[j]].push_back(a[j - 1]);
            }
        }
    }

    while(q --)
    {
        long long xr,yr;
        cin >> xr >> yr;

        queue<node> q;
        q.push({xr,w[xr] + t[l[xr]][xr],l[xr]});
        while(!q.empty())
        {
            node x = q.front();
            q.pop();

            if(x.xx == yr)
            {
                cout << x.sum + w[yr] + t[l[yr]][yr] << "\n";
                break;
            }
            for(int i = 0;i < mp[x.xx].size();i ++)
            {
                if(x.line != l[mp[x.xx][i]])
                {
                    q.push({mp[x.xx][i],x.sum + t[l[x.xx]][x.xx] + t[l[mp[x.xx][i]]][x.xx],l[mp[x.xx][i]]});
                }
                else
                {
                    q.push({mp[x.xx][i],x.sum,x.line});
                }
            }

        }
    }

    return 0;
}
