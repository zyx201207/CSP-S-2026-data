#include <bits/stdc++.h>
using namespace std;
int n;
string s = "";

long long palindrome(string a, string b)
{
	long long cnt = 0;
	reverse(b.begin(), b.end());
	for (unsigned int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) cnt++;
	}
	return cnt;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	long long a;
	char c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for (long long j = 1; j <= a; j++) s = s + c;
	}
	long long mid = s.size() / 2;
	if (s.size() % 2 == 0)
	{
		string s1 = s.substr(0, mid);
		string s2 = s.substr(mid, s.size() - mid);
		cout << palindrome(s1, s2);
	}
	else if (s.size() % 2 == 1)
	{
		string s1 = s.substr(0, mid);
		string s2 = s.substr(mid + 1, mid);
		cout << palindrome(s1, s2);
	}
	return 0;
}
