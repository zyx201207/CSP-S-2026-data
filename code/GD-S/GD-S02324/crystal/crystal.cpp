#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n, ptr;
long long a[maxn], b[maxn], ntop = 1, m, ans, nu;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
		cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    // for(int i = 1;i <= n;i++)
    // {
	// if(a[i] != a[ntop]) a[++ntop] = a[i];
	// b[ntop]++;
    // }
    ptr = 1;
    nu = 0;
    for(int i = 2;i <= n;i++)
    {
    	nu += 1ll * (a[i] - a[i - 1]) * (0ll + i - ptr);
    	while(nu > m && ptr < i)
    	{
    		nu -= a[i] - a[ptr];
    		ptr++;
		}
		ans = max(ans, 0ll + i - ptr + 1);
//		printf("i:%d nlong:%lld ptr:%d nu:%lld\n",i, 0ll + i - ptr + 1, ptr, nu);
	}
	cout << ans;
    return 0;
}
