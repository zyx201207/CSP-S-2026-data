#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
string getstr()
{
	string ret = "";
	char ch = getchar();
	for (ch;ch <= ' ';ch = getchar());
	for (ch;ch > ' ';ch = getchar()) ret += ch;
	return ret;
}
string c1, s1, c2, s2;
bool check1()
{
	return c1 == c2;
}
int gpai(string s)
{
	int ret = 0;
	for (int i = 0;i < 2;i++) ret = ret * 10 + s[i] - '0';
	return ret;
}
int gsid(string s)
{
	string tmp = "ABC";
	for (char ch : tmp)
	{
		if (ch == s[2]) return 0;
	}
	return 1;
}
int seat(string s)
{
	string tmp = "ABCDF";
	for (int i = 0;i < 5;i++)
	{
		if (tmp[i] == s[2]) return i;
	}
	return -1;
}
bool check2()
{
	return check1() && gpai(s1) == gpai(s2);
}
bool check3()
{
	return check2() && gsid(s1) == gsid(s2);
}
bool check4()
{
	return check3() && abs(seat(s1) - seat(s2)) == 1;
}
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	c1 = getstr(), s1 = getstr(), c2 = getstr(), s2 = getstr();
	write(check1()), write(check2()), write(check3()), write(check4());
	return 0;
}
