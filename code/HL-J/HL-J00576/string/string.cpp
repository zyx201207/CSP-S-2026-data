#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s = "";
	char c;int a;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		string t(a,c);
		s += t;
	}
	int cnt = 0; 
	for (int i = 0,j = s.size() - 1;i <= j;i++,j--)
	{
		if (s[i] != s[j]) cnt++;
	}
	cout << cnt;
	return 0;
}
