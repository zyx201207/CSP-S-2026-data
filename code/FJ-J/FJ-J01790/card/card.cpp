#include <bits/stdc++.h>
#define N 500001
#define M 300001
using namespace std;

int st[N], top;
int a[N], ans[N];

void check(int x)
{
	for (int i = top;i >= 1;i--)
	{
		if(st[i] == x)
		{
			top = i - 1;
			return;
		}
	}
	return;
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	
	for (int i = 1;i <= n;i++)
	{
		top = 0;
		for (int j = i;j <= n;j++)
		{
			check(a[j]);
			st[++top] = a[j];
		}
		do
		{
			ans[st[top]]++;
		}while(--top);
	}
	
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
} 
