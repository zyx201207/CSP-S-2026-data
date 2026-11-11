#include <bits/stdc++.h>
using namespace std;
int n,m,b[33],d[33];
stack<int> stk;
string s[200005];
long long ans;
bool cmp(string a,string b)
{
	return a > b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		int a,tot = 0;
		cin >> a;
		while (a)
		{
			stk.push(a % 2);
			d[tot++] += (a % 2);
			a /= 2;
		}
		while (stk.size() < 32)
			stk.push(0);
		while (!stk.empty())
		{
			s[i].push_back((char)(stk.top() + '0'));
			stk.pop();
		}
	}
	for (int i = 0;i <= 32;i++)
		if (d[i] > 0 && d[i] < m)
			for (int j = 1;j <= n;j++)
				s[j][s[j].size() - i - 1] = '0';
	sort(s + 1,s + n + 1,cmp);
	for (int i = 1;i <= m;i++)
		for (int j = s[i].size() - 1;j >= 0;j--)
			if (s[i][j] == '1')
				b[s[i].size() - j - 1]++;
//	for (int i = 0;i <= 32;i++)
//		cout << b[i] << " ";
//	cout << endl;
	for (int i = 0;i <= 32;i++)
		if (b[i] >= m)
			ans += (1 << i);
	cout << ans << endl;
	return 0;
}
/*
5 3
31 3 1 15 7

*/
