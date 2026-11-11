#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n;
long long cnt = 0;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long num;
		char c;
		cin >> num >> c;
		for (long long j = 1; j <= num; j++) s += c;
	}
	const long long size = ceil(s.size() / 2.00);
	string s1 = s.substr(0, size), s2 = s.substr(s.size() / 2, size);
	reverse(s1.begin(), s1.end());
	if (s1 == s2) cout << 0 << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (s1[i] != s2[i]) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
