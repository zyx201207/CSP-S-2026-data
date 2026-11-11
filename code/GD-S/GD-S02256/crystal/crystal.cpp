//检查long long ; 检查测试点 ; 检查freopen 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
long long m;
long long a[500010] , s[500010];
long long st[30][500010];
int lg[500010];
long long query(int pos , int len)
{
	int l = lg[len];
	return max(st[l][pos] , st[l][pos + len - 1 - (1 << l) + 1]);
}
bool check(int length)
{
	for(int i = 1 ; i + length - 1 <= n ; i++)
	{
		if(m >= query(i , length) * 1ll * length - s[i + length - 1] + s[i - 1])return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	scanf("%lld%lld" , &n , &m);
	for(int i = 1 ; i <= n ; i++)scanf("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++)s[i] = s[i - 1] + a[i];
	for(int i = 1 ; i <= n ; i++)st[0][i] = a[i];
	lg[1] = 0;
	for(int i = 2 ; i <= n ; i++)lg[i] = lg[i >> 1] + 1;
	for(int i = 1 ; i <= lg[n] ; i++)
		for(int j = 1 ; j + (1 << i) - 1 <= n ; j++)
			st[i][j] = max(st[i - 1][j] , st[i - 1][j + (1 << i - 1)]);
//	cout << query(1 , 4);
//	cout << check(4) << endl;
	int l = 1 , r = n , mid , ans = 1;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(check(mid))l = mid + 1 , ans = mid;
		else r = mid - 1;
	}
	while(check(ans))ans++;
	ans--;
	printf("%lld\n" , ans);
	return 0;
 } 
