#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int m,b,n,a,c;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		for(int j = 1;j <= a;j++)
		{
			cin >> c;
			s[i] += c;
		}
	}
	b = s.size();
	for(int i = 1;i <= b;i++)
	{
		if(s[i] != s[b-i])
		{
			m++;
		}
	}
	cout << m;
}
