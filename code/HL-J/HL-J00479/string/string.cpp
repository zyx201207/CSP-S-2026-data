#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
	string k = "";
	for (int i=s.length()-1;i>=0;i--)
	{
		k += s[i];
	}
	if (k == s)
	{
		return true;
	}
	else return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans = 0;
	string s;
	string c;
	cin >> n;
	while(n--)
	{
		cin >> a >> c;
		for (int i=1;i<=a;i++)
		{
			s += c;
		}
	}
	if (check(s) == 1)
	{
		cout << 0;
		return 0;
	}
	int pos1 = 0,pos2 = s.length()-1,ll = (s.length()+1) / 2;
	for (int i=1;i<=ll;i++)
	{
		if (s[pos1] != s[pos2])
		{
			ans ++;
		}
		pos1++;
		pos2--;
	}
	cout << ans;
	return 0;
}
