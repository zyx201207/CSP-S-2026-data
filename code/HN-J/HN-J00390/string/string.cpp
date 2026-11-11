#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	string s = "";
	for(int i = 1;i <= n;i++)
	{
		int a = 0;
		string b = "";
		cin >> a >> b;
		for(int j = 1;j <= a;j++)
		{
			s += b;
		}
	}
	long long len = s.size() - 1;
	int cnt = 0;
	for(int i = 0;i*2 <= len;i++)
	{
		if(s[i] != s[len - i])
		{
			cnt++;
		}
	}
	cout << cnt;
}
