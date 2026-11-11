#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;

int n, m;

int r[N];
int vis[N] = {0};
int weizhi[N];

inline int read() 
{
	int x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') 
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') 
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}


int main() 
{ 
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	n = read();
	m = read();
	int num = n;
	for (int i = 1; i <= n; i ++ ) 
	{
		r[i] = read();
		weizhi[r[i]] = i;
		if (vis[r[i]] == 1) 
		{
			num --;
		}
		vis[r[i]] = 1;
	}
	
	for (int i = 1; i <= num; i ++ ) 
	{
		cout << weizhi[i] << " ";
	}
}
