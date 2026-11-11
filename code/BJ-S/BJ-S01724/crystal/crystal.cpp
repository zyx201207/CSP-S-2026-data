#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ls = 1;
    int ans = 0;
    s[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        s[i] = s[i - 1] + a[i];
        while(s[i] - s[ls - 1] + m < (i - ls + 1) * 1ll * a[i]) ls++;
        ans = max(ans, i - ls + 1);
    }
    cout << ans;
    return 0;
}
