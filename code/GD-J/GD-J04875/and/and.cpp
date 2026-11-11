#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n, m, s;
int a[100005];
int p[100005];
int maxn = -100000;
void dfs(int i, int c, int sum)
{
	if(c == m){
		if(sum > maxn){
			maxn = sum;
			return;
		}
	}
	for(int j = i + 1;j <= n;j++)
	{
		dfs(j, c+1, sum & a[j]);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%d", a+i);
	for(int i = 1;i <= n;i++)
		dfs(i, 1, a[i]);
	cout << maxn;
	return 0;
}

