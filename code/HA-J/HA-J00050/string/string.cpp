#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin >> n;
	string s;
	for (int i=1;i<=n;i++)
	{
		int a;
		char x;
		cin >> a >> x;
		while (a--)
			s += x;
	}
	string ls;
	for (int i=s.length();i>=1;i--)
	{
		ls += s[i];
	}
	ls[0] = s[s.length()-1];
	cout << ls << '\n';
	cout << s << '\n';
	if (ls == s)
		cout << 0 << '\n';
	else
	{
		if (s.length() % 2 == 0)
		{
			int mid=s.length() / 2;
			char la[200005];
			int fi=0;
			for (int i=mid-1;i>=0;i--)
			{
				la[fi] = s[i];
				fi++;
			}
			fi=0;
			for (int i=mid;i<s.length();i++)
			{
				s[i] = la[fi];
				fi++;
				ans++;
			}
		}
		else
		{
			int mid=s.length() / 2;
			char la[200005];
			int fi=0;
			for (int i=mid-1;i>=0;i--)
			{
				la[fi] = s[i];
				fi++;
			}
			fi = 0;
			for (int i=mid+1;i<s.length();i++)
			{
				s[i] = la[fi];
				fi++;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
