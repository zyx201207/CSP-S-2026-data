#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N], n, m, ans[M];
stack <int> st;
bool vis[M];
void solve1()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(vis[a[j]] != 0)
			{
				while(st.top() != a[j])
				{
					vis[st.top()] = 0;
					st.pop();
				}
			}
			else
			{
				st.push(a[j]);
				vis[a[j]] = 1;
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			vis[st.top()] = 0;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	solve1();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
