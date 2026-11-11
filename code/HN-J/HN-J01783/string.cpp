#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int N = 2e5 + 5;
int n , a[N];
char s[N];
//int sy[N];
struct node
{
	char ss;
	int num;
}f1[N];
struct node2
{
	char ss;
	int num;
}f2[N];


signed main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	n = read();
	for(int i = 1;i <= n; ++ i)
	{
		a[i] = read();
		cin >> s[i];
	}
	for(int i = 1;i <= n; ++ i)
	{
		if(s[i] == s[i - 1])
		{
			a[i] += a[i - 1];
			a[i - 1] = 0;
		}
	}
	int len = 0;
	for(int i = 1;i <= n; ++ i)
	{
		if(a[i] > 0)
		{
			f1[++ len].num = a[i];
			f1[len].ss = s[i];
		}
	}
	for(int i = 1;i <= len; ++ i)
	{
		int j = len - i + 1;
		f2[j].num = f1[i].num;
		f2[j].ss = f1[i].ss;
	}
//	for(int i = 1;i <= len; ++ i)
//	{
//		cout << "f1: " << f1[i].num << " " << f1[i].ss << '\n';
//	}
//	cout << '\n';
//	for(int i = 1;i <= len; ++ i)
//	{
//		cout << "f2: " << f2[i].num << " " << f2[i].ss << '\n';
//	}
//	cout << '\n';
	int ans = 0;
	for(int i = 1 , j = 2;i <= len; ++ i)
	{
//		if(i == 1)
//		{
//			if(f)
//		}
		if(f1[i].ss != f2[i].ss)
		{
			if(f1[i].num == f2[i].num)
				ans += f1[i].num;
			else
				ans += abs(f1[i].num - f2[i].num);
//			wz[++ o] = i;
		}
		else if(f1[i].ss == f2[i].ss && f1[i].num != f2[i].num)
		{
			ans += abs(f1[i].num - f2[i].num);	
		} 
	}
	cout << ans / 2;
	return 0;
}
