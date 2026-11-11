#include <bits/stdc++.h>
using namespace std;
int n;
long long num[200001],sum,ans;
char a[200001];
string s = "";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> num[i] >> a[i];
		for (int j = 1;j <= num[i];j++)
			s += a[i];
		sum += num[i];
	}
	for (int i = 0;i < sum/2;i++)
	{
		if (s[i]!=s[sum-i+1])
			ans++;
	}
	cout << ans;
	return 0;
}
