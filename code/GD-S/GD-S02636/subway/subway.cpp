#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/* pls support shenzhen metro*/


long long c,n,m,d,q;

long long w[500009];
long long k[500009];
vector<long long> a[509];
vector<long long>t[509];


struct e
{
    long long u,v,w;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    vector<e> es(100009)
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n;i++)
    {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++)
        {
            long long aa,tt;
            cin >> aa >> tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
            if (i != 1)
            {
                es.push_back({[a[i-1],a[i],0)};
                es.push_back({[a[i],a[i-1],0)};
            }


            es.push_back({a[i],i+22000,t[i]});

        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}
