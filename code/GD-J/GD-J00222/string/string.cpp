#include <iostream>
using namespace std;

int n,a[200010],cnt1,cnt2,len;
char c[200010];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i]; 
	}
	s = " ";
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= a[i];j++)
		{
			s += c[i];
		}
	}
	len = s.size()-1;
	if (len%2 == 1)
	{
		for (int i = 1;i <= len/2;i++)
		{
			if (s[len-i+1] != s[i])
			{
				cnt1 += 1;
			}
		}
		for (int i = 1;i <= len/2;i++)
		{
			if (s[i] != s[len-i+1])
			{
				cnt2 += 1;
			}
		}
	}
	else
	{
		for (int i = 1;i <= len/2;i++)
		{
			if (s[len-i+1] != s[i])
			{
				cnt1 += 1;
			}
		}
		for (int i = 1;i <= len/2;i++)
		{
			if (s[i] != s[len-i+1])
			{
				cnt2 += 1;
			}
		}
	}
	cout << min(cnt1,cnt2) << endl;
	return 0;
}
