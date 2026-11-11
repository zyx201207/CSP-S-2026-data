#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s = "";
	cin >> n;
	if(n==1)
	{
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		int a;
		string c;
		cin >> a >> c;
		for(int i= 1;i <= a;i++)
		{
			s+=c;
			cnt++;
		}
	}
	int ans=0;
	for(int i = 1;i <= cnt/2+1;i++)
	{
		if(s[i]!=s[n-i+1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
