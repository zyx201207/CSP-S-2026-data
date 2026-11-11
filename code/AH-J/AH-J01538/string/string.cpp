#include<bits/stdc++.h>
using namespace std;
struct node
{
	char z;
	long long lon;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt = 0;
	cin >> n;
	int m = n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i - cnt].lon >> a[i - cnt].z;
		if(a[i - cnt].z == a[i - 1 - cnt].z)
		{
			a[i - cnt].z = ' ';
			a[i - 1 - cnt].lon += a[i - cnt].lon;
			a[i - cnt].lon = 0;
			cnt++;
			m--;
		}
	}
	if(m == 1)
	{
		cout << 0;
		return 0;
	}
	long long ans = 0,res = 0;
	bool flag = false;
	for(int i = 1;i <= m / 2;i++)
	{
		if(a[i].lon == a[m - i + 1].lon && i <= m / 2)
		{
			if(a[i].z != a[m - i + 1].z)
				ans += a[i].lon;
			continue;
		}
		flag = true;
	}
	if(!flag)
	{
		cout << ans;
		return 0;
	}
	ans = 0;
	string s = "";
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= a[i].lon;j++)
			s += a[i].z;
		res += a[i].lon;
	}
	for(int i = 0;i <= res / 2 - 1;i++)
	{
		if(s[i] != s[res - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}
