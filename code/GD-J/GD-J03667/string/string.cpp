#include <iostream>
#include <string> 

using namespace std;
long long lena[200005];
char c[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> lena[i] >> c[i]; 
	} 
	
	long long ans = 0;
	long long left = lena[1] , right = lena[n];
	int nowle = 1, nowri = n;
	while (nowle < nowri)
	{
		if (left > right)
		{
			if (c[nowle] != c[nowri])
			{
				ans += right;
//				cout << left << c[nowle] << '-' << right << c[nowri]; 
				left -= right;
//				cout << '=' <<left << ' ' << ans - right<< "+" << right << '=' << ans << '\n';
				right = lena[--nowri];
			}
			else 
			{
				left -= right;
				right = lena[--nowri];
			}
		}
		else if (left == right)
		{
			if (c[nowle] != c[nowri])
			{
				ans += right;
				right = lena[--nowri];
				left = lena[++nowle];
			}
			else
			{
				right = lena[--nowri];
				left = lena[++nowle];
			}
		}
		else if (left < right)
		{
			if (c[nowle] != c[nowri])
			{
				ans += left;
//				cout << right << c[nowri] << '-' << left << c[nowle]; 
				right -= left;
//				cout << '=' <<right << ' ' << ans - left<< "+" << left << '=' << ans << '\n';
				left = lena[++nowle];
			}
			else
			{
				right -= left;
				left = lena[++nowle];
				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
3 
2 a
2 b
1 c

2 
2 a
3 a

6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

4
5 h
7 s
4 m
11 a

4
5 h
3 c
9 m
9 h

*/
