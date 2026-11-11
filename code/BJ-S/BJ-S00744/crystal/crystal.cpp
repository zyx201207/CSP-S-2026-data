#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll op[100010], maxn;
ll a[100010];
struct dat
{
    ll id, num;
};
bool operator <(dat x, dat y)
{
    return x.num > y.num;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    priority_queue<dat> q;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.push({i, a[i] });
    }
    if(m > 1e8)
    {
        bool flaga = 0, flagb = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] != i)
            {
                flaga = 1;
                break;
            }
        }
        for(int i = 2; i < n; i++)
        {
            if(a[i] - a[i-1] != a[i+1] - a[i])
            {
                flagb = 1;
                break;
            }
        }
        if(flaga)
        {
            cout << int(sqrt(2 * m)) << endl;
        }
        if(flagb)
        {
            cout << int(sqrt(m * 1.0 / (a[2] - a[1])));
        }
        return 0;
    }
    int ans = -1e9;
    while(m)
    {
        dat t = q.top();
        q.pop();
        m--;
        a[t.id]++;
        q.push({t.id, t.num + 1});
    }
    while(!q.empty())
    {
        dat t = q.top();
        q.pop();
        op[t.num]++;
    }
    for(int i = 1; i <= n; i++)
    {
        maxn = max(maxn, op[a[i]]);
    }
    cout << maxn << endl;
    return 0;
}
