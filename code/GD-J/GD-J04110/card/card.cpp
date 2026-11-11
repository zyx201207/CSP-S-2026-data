#include <bits/stdc++.h>
using namespace std; 

int n, m, a[300005], ans[300005]; 

void solve(int i)
{
	vector <int> pos(m+1, 0); 
	int c[300005], fir = 1, tit = 0; 
	for (int j = i; j <= n; j++)
	{
		tit++; 
		c[tit] = a[j]; 
		if (pos[a[j]]) tit = pos[a[j]]; 
		else pos[a[j]] = tit; 
	}
	for (int j = fir; j <= tit; j++)
	{
		ans[c[j]]++; 
	}
}

int main()
{
	freopen("card.in", "r", stdin); 
	freopen("card.out", "w", stdout); 
	
	cin >> n >> m; 
	vector <int> ans(m+1, 0); 
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	}
	
	for (int i = 1; i <= m; i++)
	{
		solve(i); 
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' '; 
	}
}
