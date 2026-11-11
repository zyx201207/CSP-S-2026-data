#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 5;
ll n , a[N]  , som = 0 , ans = 0;
char c[N];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(ll i = 1 ; i <= n ; i ++)
	{
		ll x;
		char y;
		cin >> x >> y;
		a[i] = x;
		c[i] = y;
		som += x;
	}
	ll t;
	if(som % 2 == 1)
	{
		som = som / 2 + 1;
		t = 1;
	}
	else
	{	
		som = som / 2;
		t = 0;
	}
	ll s1 = som , i = 1 , j = 1 , x = 0 , y = 0;
	while(s1 >= 0)
	{
		if(s1 - a[i] > 0)
		{
			s1 -= a[i];
			i ++;
			j ++;
		}
		else if(s1 == a[i])
		{
			j ++;
			break;
		}
		else
		{
			x = s1 - t;
			y = a[i] - s1;
			if(x == 0) i --;
			if(y == 0) j ++;
			break;
		}
	}
	while(i > 0 && j <= n)
	{
		if(x == 0) x = a[i];
		if(y == 0) y = a[j];
		if(c[i] == c[j])
		{
			if(x > y)
			{
				x -= y;
				j ++;
				y = 0;
			}
			else if(x == y)
			{
				i --;
				j ++;
				x = 0;
				y = 0;
			}
			else if(x < y)
			{
				y -= x;
				i --;
				x = 0;
			}
		}
		else
		{
			if(x > y)
			{
				x -= y;
				j ++;
				ans += y;
				y = 0;
			}
			else if(x == y)
			{
				i --;
				j ++;
				ans += y;
				x = 0;
				y = 0;
			}
			else if(x < y)
			{
				y -= x;
				i --;
				ans += x;
				x = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
