#include<bits/stdc++.h>
using namespace std;
int n;
long long a,b,ans;
char c;
string r;
int main()
{
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> c;
		b += a;
		for (int j = 1;j <= a;j++)
		{
			r = r + c;
		}
	}
	for (int i = 0;i < b;i++)
	{
		if (r[i] != r[b-1-i])
		{
			ans++;
			r[b-1-i] = r[i];
		}
	}
	cout << ans;
	return 0;
}
