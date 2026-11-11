#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string S;
	vector<long long> a(n + 1);
	vector<string> s(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cin >> s[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(long long j = 1;j <= a[i];j++)
		{
			S += s[i];
		}
	}
	long long ans = 0;
	for(long long i = 0;i < S.size() / 2;i++)
	{
		if(S[i] != S[S.size() - i - 1])
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
