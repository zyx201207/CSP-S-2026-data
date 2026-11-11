#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, a[N];
char c[N];
string s = "0";
string in(int x)
{
	string t="";
	for(int i = 1; i <= a[x]; i++)
		t+=c[x];
	return t;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int flag = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		if(i!=1&&c[i]!=c[i-1])flag=0;
	}
	if(flag)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		s += in(i);
	}
	int cnt = 0;
	for(int i = s.size()-1; i >= 1; i--)
	{
		if(s[i] != s[s.size()-i])
		{
			cnt++;
		}
		//printf("s[%d]=%c s[%d]=%c\n", i, s[i], s.size()-i, s[s.size()-i]);
	}
	cout << cnt/2;
	return 0;
}
/*
0 1 2 3 4
a a b b c
i 0 1 2 3 4
  a a b b c
  c b b 
j 4 3 2 1 0
*/
