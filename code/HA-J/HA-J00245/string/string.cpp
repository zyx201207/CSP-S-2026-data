#include<bits/stdc++.h>//正在接受暴力的洗礼 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int ans = 0;
	cin>>n;
	string s;
	for(int i = 1;i <= n;i++)
	{
		int a;char c;
		cin>>a>>c;
		for(int j = 1;j <= a;j++)
		{
			s += c;
		}
	}
	if(s.length() % 2 != 0)
	{
		for(int i = s.length() / 2;i <= s.length() - 1;i++)
		{
			if(s[i] != s[s.length() - i - 1])
			{
				ans++;
				//cout<<i<<s[i]<<' '<<s[s.length() - i - 1]<<endl;
			}
		}
	}
	else
	{
		for(int i = s.length() / 2;i <= s.length() - 1;i++)
		{
			if(s[i] != s[s.length() - i - 1])
			{
				ans++;
				//cout<<s[i]<<' '<<s[s.length() - i - 1]<<endl;
			}
		}
	}
	cout << ans;
	return 0;
}
