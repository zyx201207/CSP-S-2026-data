#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

struct Node
{
	ll cnt, l, r;
	char c;
}a[N];

int n;
ll pre[N];

ll findr(ll x)
{
	int l = 1, r = n;
	while(l < r)
	{
		int mid = l + (r - l) / 2;
		if(a[mid].r < x) l = mid + 1;
		else r = mid;
	}
	
	return 1LL * l;
}

ll findl(ll x)
{
	int l = 1, r = n;
	while(l < r)
	{
		int mid = l + (r - l + 1) / 2;
		if(a[mid].l > x) r = mid - 1;
		else l = mid; 
	}
	
	return 1LL * l;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);	
	
	ll len = 0;
	cin >> n;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].cnt >> a[i].c;
		a[i].l = pre[i - 1] + 1;
		pre[i] = pre[i - 1] + a[i].cnt;
		a[i].r = a[i].l + pre[i] - pre[i - 1] - 1;
		len += a[i].cnt;
	}
	
	if(len <= (ll)1e8)
	{
		string s = "#";
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= a[i].cnt;j++)
			{
				s += a[i].c; 
			}
		}
		
		ll ans = 0;
		for(int i = 1;i <= len;i++)
		{
			ans += (s[i] != s[len - i + 1]);
		}
		
		cout << ans / 2;
		return 0;
	} 
	
	ll ans = 0;
	for(int i = 1;i <= n;i++)
	{
		ll q = len + 1 - a[i].l, p = len + 1 - a[i].r;
		ll k = findr(q);
		ll j = findl(p);
		for(int m = j;m <= k;m++)
		{
			if(a[m].c != a[i].c)
			{
				if(a[m].l < p)
					ans += llabs(p - a[m].r) + 1;
				else if(q < a[m].r)
					ans += llabs(q - a[m].l) + 1;
				else ans += a[m].cnt; 
			}
		}
	}
	
	cout << ans / 2;
	
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
}
