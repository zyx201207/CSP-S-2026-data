#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn = 5e5;
ll n, m, tar, mid=2,k;
ll c[Maxn+10];
void f()
{
    tar = c[mid];
    if(mid+1 > n) return;
    if(tar == c[mid-1]&&(c[mid+1]-tar)*mid<=m)
    {
        k=c[mid+1]-tar;
        ++mid;
        f();
        return;
    }

    for(ll i = mid-1; i>=1; i--)
    {
        m-=k;
        c[i]+=k;
    }
    k=c[mid+1]-tar;
    if(k*mid<=m)
    {
        ++mid;
        f();
        return;
    }
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n,&m);
    for(ll i = 1; i <= n; i++) scanf("%lld", &c[i]);
    sort(c+1, c+n+1);
    k=c[2]-c[1];
    f();

    for(ll i = mid+1; i<=n; i++)
    {
        if(mid+1>n||c[i] != tar) break;
        mid++;
    }
    printf("%lld", mid);
    return 0;
}
