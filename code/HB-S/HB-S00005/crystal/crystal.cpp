#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

const int N = 5e5 + 7;
ll n, m, a[N], t = 0;
int ans = 1;
queue<ll> q;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++)scanf("%lld", &a[i]);
    sort(a, a + n);
    for(ll i = 1; i <= n; i++)
    {
        t += q.size() * (a[i] - a[i - 1]), q.push(i);
        while(t > m)
        {
            t -= a[i] - a[q.front()];
            q.pop();
        }
        ans = (ans < q.size()) ? q.size() : ans;
    }
    printf("%d", ans);
    return 0;
}
