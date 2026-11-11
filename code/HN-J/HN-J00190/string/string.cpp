# include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL n , m , cnt , a[N] , s[N];
char c[N];
void solve()
{
	cin >> m;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> a[i] >> c[i] , n += a[i];
		s[i] = s[i - 1] + a[i];
	}
	LL p = lower_bound(s + 1 , s + m + 1 , n / 2) - s;
	int i , j;
	for(i = 1 , j = m ; i <= p || j > p ;)
	{
		if(a[i] <= a[j])
		{
			cnt += (c[i] != c[j]) * a[i];
			a[j] -= a[i] , a[i] = 0 , i ++;
			if(!a[j]) j --;
		}
		else
		{
			cnt += (c[i] != c[j]) * a[j];
			a[i] -= a[j] , a[j] = 0 , j --;
			if(!a[i]) i ++;
		}
	}
	cout << cnt;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in" , "r" , stdin); 
	freopen("string.out" , "w" , stdout);
	int t = 1;
	while(t --) solve();
	return 0;
}
