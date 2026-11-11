#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int a[N];
char s[N][35];
bool flag[N];

void get_s(int x, int i)
{
	string str;
	while (x)
	{
		str += ((x % 2) + '0');
		x /= 2;
	}
	reverse(str.begin(), str.end());

	string l;
	for (int i = 1; i <= 30 - str.size(); i ++ ) l += '0';
	str = l + str;
	
	for (int k = 1; k <= 30; k ++ ) s[i][k] = str[k - 1];
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) 
	{
		scanf("%d", &a[i]);
		get_s(a[i], i);
	}
	
	for (int i = 1; i <= n; i ++ ) flag[i] = true;
	
	int res = 0;
	for (int k = 1; k <= 30; k ++ )
	{
		int cnt = 0;
		for (int i = 1; i <= n; i ++ )
			if (flag[i])
			{
				if (s[i][k] == '1') 
					cnt ++ ;
			}
		
		if (cnt >= m)
		{
			res += (1 << 30 - k);
			for (int i = 1; i <= n; i ++ )
				if (flag[i])
				{
					if (s[i][k] != '1') flag[i] = false;
				}
		}
	}
	
	printf("%d\n", res);
	return 0;
}
