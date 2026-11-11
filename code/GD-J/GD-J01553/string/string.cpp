#include<bits/stdc++.h>
using namespace std;

struct s
{
	int num;
	char c;
};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k;
	s a[200000];
	long long ans = 0;
	cin >> n;
	k = n;
	a[0].c = 'A';
	int p = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i - p].num >> a[i - p].c;
		if(a[i - p].c == a[i - 1 - p].c)
		{
			a[i - 1 - p].num += a[i - p].num;
			p++;
			k -= 1;
		}
	}
	for(int i = 1;i <= k / 2;i++)
	{
		int x = k + 1 - i;
		if(a[i].num == a[x].num && a[i].c != a[x].c )
		{
			ans += a[i].num;
		}
		else if(a[i].num == a[x].num && a[i].c == a[x].c )
		{
			continue;
		}
		else if(a[i].num != a[x].num && a[i].c != a[x].c )
		{
			ans += max(a[i].num,a[x].num);
		}
		else
		{
			ans += max(a[i].num,a[x].num) - min(a[i].num,a[x].num);
		}
	}
	cout << ans;
	return 0;
}
