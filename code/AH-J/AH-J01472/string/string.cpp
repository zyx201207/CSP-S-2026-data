#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005], ans, s[200005], sum;
char b[200005];
int check(long long x)
{
	int l = 0, r = n;
	while(l <= r)
	{
		int m = (l + r) >> 1;
		if(s[m] >= x)
			r = m - 1;
		else
			l = m + 1;
	}
	return r;
}
bool f;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> b[i];
		if(i != 1 && b[i] != b[i - 1])
			f = 1;
		s[i] = s[i - 1] + a[i - 1];
		sum += a[i];
	}
	if(!f)
	{
		cout << 0;
		return 0;
	}
	long long t1 = 1, t2;
	for(int i = n; i >= 1; i --)
	{
		t2 = t1 + a[i] - 1;
		int s1 = check(t1), s2 = check(t2);
//		cout << i << ' ' << s1 << ' ' << s2 << '\n';
		if(b[s1] == b[i])
			ans += s[s1 + 1] - t1;
		else if(b[s2] == b[i])
			ans += t2 - s[s2];
//		cout << ans << '\n';
		t1 = t2 + 1;
	}
	cout << (sum - ans - 1) / 2;
	return 0;
}
