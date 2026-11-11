#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n , m;
int a[N] , ans;

signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin>>a[i];
	}
	sort(a + 1 , a + n + 1);
	int used = 0 , len = 1;
	for(int i = 1 , j = 2 ; j <= n ; j ++)
	{
		len++;
		used += (len - 1) * (a[j] - a[j - 1]);
		while(used > m)
		{
			used -= a[j] - a[i];
			len--;
			i ++;
		}
		ans = max(ans , len);
	}
	cout<<ans;
}
