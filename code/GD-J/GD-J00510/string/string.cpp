#include <bits/stdc++.h>
using namespace std;
string S1;
char m;
long long ans,n,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> m;
		string S2(a,m);
		S1 += S2;
	}
	long long l = 0,r = S1.size() - 1;
	for (int i = 0;i < S1.size();i++)
	{
		if (S1[l] != S1[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout << ans / 2;
	return 0;
} 
