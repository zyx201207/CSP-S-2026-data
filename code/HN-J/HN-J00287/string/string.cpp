#include<bits/stdc++.h>
using namespace std;
#define int long long
char c[200005];
int n , l , ans;
int zd[200005] , yd[200005] , a[200005];
signed main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
		yd[i] = l;
	}
	int w;
	for(int i = 1; i <= n; i ++)
	{
		if(yd[i] >= (l + 1) / 2 && yd[i - 1] < (l + 1) / 2)w = i;
	}
	int m = (l + 1) / 2;
	int L = w - 1 , R = w;
	int sl = m - yd[L] - 1 , sr = yd[R] - m;
	if(l % 2 == 0)sl = m - a[L];
	char cl = c[L + 1] , cr = c[R];
	while(L > 0 || R < n)
	{
		if(cr != cl)ans += min(sl , sr);
		if(sr < sl)
		{
			sl -= sr;
			R ++;
			sr = a[R];
			cr = c[R];
		}
		else
		{
			sr -= sl;
			L --;
			sl = a[L + 1];
			cl = c[L + 1];
		}
	}
	if(sl == sr && cl != cr)ans += sl;
	cout << ans;
	return 0;
}
