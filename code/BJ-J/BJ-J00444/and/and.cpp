#include <bits/stdc++.h>
using namespace std;

int a[200005] , f[200005];
int n , m , maxn = -2e9;

int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1 , a + n + 1 , greater<int>() );
    int ans;
    for (int i = 1; i <= m; i++)
    {
        if (i == 1) ans = a[i];
        else ans = (ans & a[i]);
    }
    cout<< ans;
    return 0;
}
