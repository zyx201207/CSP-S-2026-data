#include <bits/stdc++.h>
using namespace std;
int a[200005];
string c[200005];
int n;
int cnt[200005];
stack<int> st;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string h;
	bool f = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++)
		{
			h = c[i];
		}
		if(h == c[i])
		{
			f = 1;
		}
	}
	if(f == 1)
	{
		cout << 0;
		
	 } 
	return 0; 
}
