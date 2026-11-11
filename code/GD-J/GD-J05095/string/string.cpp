#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
char let[N];
int letn[N];

bool huiwen(string s)
{
	int l = 0,r = s.size()-1;
	while (l <= r)
	{
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

int Gai(string s)
{
	int l = 0,r = s.size()-1;
	long long ans = 0;
	while (l <= r)
	{
		if (s[l] != s[r])
		{
			s[r] = s[l];
			ans++;
		}
		l++;
		r--;
	}
	return ans;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> letn[i] >> let[i];
		if (letn[i] >= 1e9) return 0;
		for (int j = 1;j <= letn[i];j++)
		{
			s += let[i];
		}
	} 
	if (huiwen(s))
	{
		cout << 0;
		return 0;
	}
	long long ans = Gai(s);
	cout << ans;
	return 0;
}
