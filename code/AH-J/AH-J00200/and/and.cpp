#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2e5 + 5;
ll n, m;
struct add  //114514
{
	string s;
	ll as;
}a[MAXN];
void turn (ll x, ll y)
{
	ll i = 1;
	string z = " ";
	while(x >= 1)
	{
		char ss =  x % 2 + '0'; 
		z += ss;
		x /= 2;
		i++;
	}
	a[y].s = z;
	a[y].as = i - 1;
	return ;
}
bool cmp(add x, add y)
{
	if(x.as == y.as) return x.s > y.s;
	return x.as > y.as; 
}
string ad(string x, string y, ll xl, ll yl)
{
	string z = " ";
	for(ll i = 1; i <= min(xl, yl); i++)
	{
		if(x[i] == y[i]) z += x[i];
		else z += "0"; 
	}
	return z;
}
ll turndown(string x, ll xl)
{
	ll y = 1, ss = 0;
	for(ll i = 1; i <= xl; i++)
	{
		ss += y * (x[i] - '0');
		y *= 2;
	}
	return ss;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
	{
		ll x;
		cin >> x;
		turn(x, i);
	}
	sort(a + 1, a + 1 + n, cmp);
	string mx = a[1].s;
	ll ml = a[1].as;
		cout << mx << " " << ml << "\n";
	for(ll i = 2; i <= m; i++)
	{
		mx = ad(mx, a[i].s, ml, a[i].as);
		ml = min(ml, a[i].as);
		cout << a[i].s << " " << ml << "\n";
	}
	cout << turndown(mx, ml);
	return 0;
} 
