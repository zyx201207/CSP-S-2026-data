#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	long long a;char c;string s;
	for(int i = 0;i < n;i++)
	{
		cin >> a >> c;
		for(int j = 0;j < a;j++)
		{
			s += c;
		}
	}
	
	long long ans = 0;
	for(int i = 0;i < ((s.size() + 1) / 2);i++)
	{
		if(s[i] - s[s.size() - i - 1])
		{
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}
