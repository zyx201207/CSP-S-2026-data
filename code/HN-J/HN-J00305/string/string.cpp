#include <bits/stdc++.h>
#define int long long
using namespace std;

int n , L , l = 0 , l2 = 0 , ans , qz , qzs , qz2 , qz2s;
int a[10000005] , b[10000005];
map<char , int>mp;

struct node
{
	int x;
	char c;
}wrq[200005];


signed main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	mp['d'] = 4;
	mp['e'] = 5;
	mp['f'] = 6;
	mp['g'] = 7;
	mp['h'] = 8;
	mp['i'] = 9;
	mp['j'] = 10;
	mp['k'] = 11;
	mp['l'] = 12;
	mp['m'] = 13;
	mp['n'] = 14;
	mp['o'] = 15;
	mp['p'] = 16;
	mp['q'] = 17;
	mp['r'] = 18;
	mp['s'] = 19;
	mp['t'] = 20;
	mp['u'] = 21;
	mp['v'] = 22;
	mp['w'] = 23;
	mp['x'] = 24;
	mp['y'] = 25;
	mp['z'] = 26;
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> wrq[i].x >> wrq[i].c;
		L += wrq[i].x;
	}
	bool f = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(f == 1)
		{
			b[l2 + 1] += mp[wrq[i].c] , b[l2 + wrq[i].x] -= mp[wrq[i].c];
			l2 += wrq[i].x;
		}	
		if(l + wrq[i].x <= L / 2)
		{
			a[l + 1] += mp[wrq[i].c] , a[l + wrq[i].x] -= mp[wrq[i].c];
			l += wrq[i].x;
		}
		else if(l <= L / 2 && l + wrq[i].x > L / 2)
		{
			a[l + 1] += mp[wrq[i].c] , a[L / 2 + 1] -= mp[wrq[i].c];
			if(l % 2 == 0)
			{
				b[l2 + 1] += mp[wrq[i].c] , b[l2 + (wrq[i].x + l - L / 2)] -= mp[wrq[i].c];
				l2 += (wrq[i].x + l - L / 2);
			}
			else
			{
				b[l2 + 1] += mp[wrq[i].c] , b[l2 + (wrq[i].x + l - L / 2 - 1)] -= mp[wrq[i].c];
				l2 += (wrq[i].x + l - L / 2 - 1);				
			}
			f = 1;
		}
	}
	for(int i = 1;i <= L / 2;i ++)
	{
		qz = qzs + a[i];
		qz2 = qz2s + b[i];
		int h = qz , k = qz2;
		if(a[i] < 0)
		{
			h = -a[i];
		}
		if(b[i] < 0)
		{
			k = -b[i];
		}
		if(h != k)
		{
			ans ++;
		}
		qzs = qz , qz2s = qz2;
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
/*
2
2 a
3 a
*/
