#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	// ...
	
	string s, temps;
	int n = 0, temp = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp >> temps;
		for (int i = 0; i < temp; i++)
		{
			s = s + temps;
		}
		temp = 0;
	}
	
	cout << s << endl;
	
	/*string res;
	
	for (int i = 0; i < s.length(); i++)
	{
		res = res + s[s.length() - i - 1];
	}
	
	cout << res;*/
	
	long long count = 0;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[s.length() - i - 1]) count += 1;
		else continue;
	}
	
	int ans = count / 2;
	
	return 0;
}
