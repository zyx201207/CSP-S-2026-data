#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i<=n;i++)	
	{
		cin >> a >> c;
		for (int j = 1;j<=a;j++)
			s+=c;
	}
	for (int i = (s.length()+1)/2+1;i<=s.length();i++)
	{
		if (s[i-1] != s[s.length()-i])	ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
