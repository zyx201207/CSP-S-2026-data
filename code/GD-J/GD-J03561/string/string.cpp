#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
	char c;
	ll x;
}a[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	ll cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i].x >> a[i].c;
	for(int l = 1, r = n; l < r; )
	{
		if(a[l].c == a[r].c)
		{
			if(a[l].x > a[r].x)
			{
				a[l].x -= a[r].x;
				r --;
			}
			else if(a[l].x < a[r].x)
			{
				a[r].x -= a[l].x;
				l ++;
			}
			else
			{
				l ++, r --;
			}
		}
		else
		{
			if(a[l].x > a[r].x)
			{
				a[l].x -= a[r].x;
				cnt += a[r].x;
				r --;
			}
			else if(a[l].x < a[r].x)
			{
				a[r].x -= a[l].x;
				cnt += a[l].x;
				l ++;
			}
			else
			{
				cnt += a[l].x;
				l ++, r --;
			}
		}
	}
	cout << cnt;
}
