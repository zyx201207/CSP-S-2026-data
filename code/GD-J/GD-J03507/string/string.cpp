#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, l;
struct node
{
	int m;
	char c;
} t[200005], a[200005];
char c[200005];
int ans;
void init()
{
	for(int i = 1;i < n;i++)
	{
		int j = i + 1;
		while(t[i].c == t[j].c)
		{
			t[i].m += t[j].m;
			t[j].m = 0;
			j++;
		}
		i = j - 1;
	}
	for(int i = 1;i <= n;i++)
	{
		if(t[i].m != 0)
			a[++l] = t[i];
	}
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> t[i].m >> t[i].c;
	init();
	int i = 1, j = l;
	for(;i <= l / 2 && i < j;)
	{
		if(a[i].m == a[j].m && a[i].c == a[j].c)
		{
			i++, j--;
			continue;
		}
		if(a[i].c != a[j].c)
			ans += min(a[i].m, a[j].m);
		if(a[i].m == a[j].m)
			i++, j--;
		else if(a[i].m > a[j].m)
		{
			a[i].m -= a[j].m;
			j--;
		}
		else
		{
			a[j].m -= a[i].m;
			i++;
		}
	}
	cout << ans;
	return 0;
}
