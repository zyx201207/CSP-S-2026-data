#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char m[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> m[i];
		s += a[i] * m[i];
	}
	cout << s;
	return 0;
}
