#include<bits/stdc++.h>

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
const int N = 5e5 + 5;
int n , m; 
struct node
{
	int x;
	bool f = 1;
}a[N];
int s[N];
void go(int x)
{
	for(int i = x;i <= n; ++ i)
	{
		if(a[i].f == 0)
		{
			continue;
		}
		for(int j = i + 1;j <= n; ++ j)
		{
			if(a[j].f == 0 || a[i].f == 0)
				continue;
			if(a[j].f == 1 && a[i].f == 1 && a[j].x == a[i].x)
			{
				for(int k = x;k <= j - 1; ++ k)
				{
//					cout << k << " " << a[k].x << '\n';
					a[k].f = 0;
				}
				break;
			}
		}
	}
//	cout << '\n';
	for(int i = x;i <= n; ++ i)
	{
//		cout << a[i].f << '\n';
		if(a[i].f == 1)
		{
			s[a[i].x] ++;
//			cout << i << " " << a[i].x << '\n';
		}
		a[i].f = 1;
	}
}

int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	n = read() , m = read();
	for(int i = 1;i <= n; ++ i)
	{
		a[i].x = read();
	}
	for(int i = 1;i <= n; ++ i)
	{
		go(i);
//		cout << '\n';
	}
	for(int i = 1;i <= m; ++ i)
	{
		cout << s[i] << " ";
	}
	return 0;
}
