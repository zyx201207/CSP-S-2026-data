#include<bits/stdc++.h>
using namespace std;
long long c, t;
long long n1[1000005], d1[1000005];
long long x[2000005];
long long cnt = 0, ans[10000005];

struct node()
{
    long long n[10000005];
    long long d[10000005];
};
long long node[10000005];

int main()
{
    freopen("mlgrate.in", "r", stdin);
    freopen("mlgrate.out", "w", stdout);
    cin >> c >> t;
    long long r, l;
    for(long long i = 1; i <= t; i++)
    {
        cin >> node.n[i] >> node.d[i];
        cin >> x[i];
    }
    r = i;
    l = x.size();
    for(long long i = 0; i <= (l-1)*l; i++)
    {
        for(int j = node.d; j <= x.size(); j += node.n)
        {
            cnt++;
        }
        ans[i]++;
    }
    cout << ans;
    return 0;
}
