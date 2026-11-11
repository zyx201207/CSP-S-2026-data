#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct st
{
	ll a;
	char b;
} v[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);     cout.tie(0);
	
	ll n, lt1 = 0, lt2 = 0, ans = 0;
	cin >> n;
	
	for (ll i = 1; i <= n; i++)
		cin >> v[i].a >> v[i].b;
	
	for (ll i = 1, j = n; i <= j; i++, j--)
	{
		if (lt1 != 0)
		{
			i--;
			ll q = abs(max(lt1, v[j].a + lt2) - abs(lt1 - lt2 - v[j].a)), w = 0, e = 0;
	
			if (v[i].b != v[j].b)
				ans += q;
	
			if (v[j].a + lt2 > lt1)
				w = abs(lt1 - lt2 - v[j].a);
			else e = abs(lt1 - lt2 - v[j].a);
		
			lt1 = e;
			lt2 = w;
			
			continue;
		}
		
		if (lt2 != 0)
		{
			j++;
			ll q = abs(max(lt2, v[i].a + lt1) - abs(v[i].a + lt1 - lt2)), w = 0, e = 0;
		
			if (v[i].b != v[j].b)
				ans += q;
		
			if (lt2 > v[i].a + lt1)
				w = abs(v[i].a + lt1 - lt2);
			else e = abs(v[i].a + lt1 - lt2);
		
			lt1 = e;
			lt2 = w;
			
			continue;
		}
		
		ll q = abs(max(v[i].a, v[j].a) - abs(v[i].a - v[j].a)), w = 0, e = 0;
		
		if (v[i].b != v[j].b)
			ans += q;
		
		if (v[j].a > v[i].a)
			w = abs(v[i].a - v[j].a);
		else e = abs(v[i].a - v[j].a);
		
		lt1 = e;
		lt2 = w;
	}
	
	cout << ans << '\n';
	return 0;
} 
