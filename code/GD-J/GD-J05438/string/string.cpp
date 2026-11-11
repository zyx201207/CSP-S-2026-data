#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in" , "w" , stdin);
	freopen("string.out" , "r" , stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	string s = "";
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= a[i]; j++)
		{
			s = s + c[i];
		}
	}
	int ans = 0;
	for(int i = 0; i <= sum / 2 - 1; i++)
	{
		if(s[i] != s[sum - i - 1]) ans++;
	}	
	cout << ans;
	return 0;
}


