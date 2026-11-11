#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const long long N = 2e5+5;
long long a[N];
char t[N];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	string s;
	for(long long i = 1;i<=n;i++)
	{
		cin >> a[i] >> t[i];
		for(int j = 1;j<=a[i];j++)
		{
			s += t[i];
		}
	}
	int m = s.size();
	int ans = 0;
	s = '?' + s;
	for(long long i = 1;i<=m;i++)
	{
		int j = m - i + 1;
		if(s[i] != s[j])ans++;
	}
	cout << ans / 2;
	return 0;
}
//72pts
