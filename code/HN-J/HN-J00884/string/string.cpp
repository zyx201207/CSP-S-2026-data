#include<bits/stdc++.h>
using namespace std;

int n;
string s, ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a;
		string c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
			s+=c;
	}
	
	
	
	cout << ans;
	
	
	return 0;
}
