#include <bits/stdc++.h>
using namespace std;
#define MAXN 500007
typedef long long ll;

ll a[MAXN];
ll f[MAXN];
ll n, m, ans = 1;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    sort(a + 1, a + 1 + n);
    f[n] = 0;
    for(int i = 1; i<n; i++){
        f[i] = a[i+1]-a[i];
    }
    ll r = 1, l = 1;
    ll t = 0;
    while(r<=n){
        r++;
        t+=f[r-1]*(r-l);
        ll cnt = 1;
        while(t>m&&l<r){ 
            t-=f[l]*cnt;
            l++;
            cnt++;
        }
        ans = max(ans, r-l+1);
    }
    printf("%lld", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}