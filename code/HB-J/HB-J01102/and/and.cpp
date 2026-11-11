#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long a[MAXN];

//int andB(int a, int b)
//{
//	string s1, s2, s3;
//	int c = 0;
//	while (a / 2 != 0)
//	{
//		s1 = s1 + (a % 2 - '0');
//		a = a / 2;
//	}
//	while (b / 2 != 0)
//	{
//		s2 = s2 + (b % 2 -'0');
//		b = b / 2;
//	}
//	while (s1.length() > s2.length())
//		s2 = s2 + '0';
//	while (s1.length() < s2.length())
//		s1 = s1 + '0';
//	for (int i = s1.length() - 1; i >= 0; i--)
//		s3[i] = s1[i] && s2[i];
//	for (int i = s3.length() - 1; i >= 0; i--)
//		c = c + s3[i] * pow(2,(i + 1 - s3.length()));
//	return c;
//}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m, n, maxx = -999;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (maxx < a[i])
			maxx = a[i];
	}
	if (m == 1)
	{
		cout << maxx << endl;
		return 0;
	}
//	if (m == 2)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = i + 1; j <= n; j++)
//				maxx = max(maxx, andB(i, j);
//		}
//		cout << maxx << endl;
//		return 0;
//	}
}
