#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[200005] = {};
	char c[200005] = {};
	string s = "";
	int n;
	long long ans = 0;
	cin >> n;
	for(int i=1; i<=n; i++) 
	{
		cin >> a[i] >> c[i];
	}
	for(int i=1; i<=n/2; i++)
	{
		if(c[i] == c[n-i+1]) continue;
		else ans+=a[i];
	}
	cout << ans;
	return 0;
}
