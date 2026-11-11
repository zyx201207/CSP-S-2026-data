#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],c = 0;
	char b[200005];
	string s;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i] >> b[i];
		for (int j = 1;j <= a[i];j++)
		{
			s += b[i];
		}
	}
	for (int i = 0;i < n;i++)
	{
		if (s[i] != s[n - 1 - i])
		{
			c++;
		}
	}
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
