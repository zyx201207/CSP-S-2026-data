#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,lst = -1,tot,ans;
struct Node{
	ll l,r;
	char c;
};
vector<Node> v,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		ll a;
		char c;
		cin >> a >> c;
		tot += a;
		if (i == 1)
		{
			Node nw;
			nw.l = 1;
			nw.r = a;
			nw.c = c;
			v.push_back(nw);
			lst = 0; 
		}
		else if (v[lst].c == c)
		{
			v[lst].r += a;
		}
		else
		{
			Node nw;
			nw.l = v[lst].r + 1;
			nw.r = nw.l + a - 1;
			nw.c = c;
			v.push_back(nw);
			lst++;
		}
	}
	if (lst == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0;i <= lst;i++)
	{
		Node nw;
		nw.l = tot + 1 - v[i].r;
		nw.r = tot + 1 - v[i].l;
		nw.c = v[i].c;
		s.push_back(nw);
	}
	for (ll i = 0,j = lst;i <= lst && j >= 0;)
	{
		if (v[i].l > (tot + 1) / 2 || s[j].l > (tot + 1) / 2)
			break;
		if (v[i].r < s[j].r)
		{
			if (v[i].c != s[j].c)
				ans += (v[i].r - v[i].l + 1);
			s[j].l = v[i].r + 1;
			i++;
		}
		else
		{
			if(v[i].c != s[j].c)
				ans += (s[j].r - s[j].l + 1);
			v[i].l = s[j].r + 1;
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
