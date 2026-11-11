#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+10;
LL n, m;
unsigned long long a[N];
string s[N];
string d(LL x)
{
	int p[33]={}, cnt = 0, temp = a[x];
	while(temp)
	{
		cnt++;
		p[cnt] = temp%2;
		temp/=2;
	}
	string num;
	for(int i = cnt; i >= 1; i--)
	{
		num += (p[i]+'0');
	}
	return num;
}
string yu(int i, int j)
{
	int hhh = max(s[i].size(), s[j].size());
	string aaaa ="";
	for(int ii = hhh-1; ii > 0; ii--)
	{
		if(s[i][ii]==s[j][ii])
			aaaa+='1';
		else aaaa+='0';
	}
	return aaaa;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout << a[n];
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		s[i] = d(i);
	}
	string maxn="0";
	for(int k = 1; k <= m; k++)
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{
				maxn = max(maxn,yu(i,j));
			}
		}
	}
	cout << maxn;
	return 0;
}
/*
1 20 33 51 44
1 10100 100001 110011 101100
1&20=0
1&33=1
1&51=1
1&44=0
20&33=
*/
