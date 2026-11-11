#include <bits/stdc++.h>
using namespace std;
char c[1000000005];
int main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long l =0;
	int n, pos = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int x1;
		char x2;
		cin >> x1 >> x2;
		l+=x1;
		while(x1--)
		{
			c[++pos] = x2; 
		}
	}
	long long ans = 0;
	for(int i = 1;i <= l/2;i++)
	{
		if((int)c[i]!=(int)c[l-i+1]) ans++;
	}
	cout <<ans;
	return 0;
}
