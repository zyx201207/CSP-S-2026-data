#include <bits/stdc++.h>
using namespace std;

long long a[200005];
string c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin >> n;
	int cnt = 0;
	string ans = "";
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= a[i];j++)
		{
			ans += c[i];
		}
	}
	if(ans.size() % 2 == 1)
	{
		int k = (ans.size() - 1) / 2;
		for(int i = k + 1;i < ans.size();i++)
		{
			if(ans[i] != ans[ans.size() - i - 1]) cnt++;
		}
	}
	else
	{
		int k = ans.size() / 2;
		for(int i = k;i < ans.size();i++)
		{
			if(ans[i] != ans[ans.size() - i - 1]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
