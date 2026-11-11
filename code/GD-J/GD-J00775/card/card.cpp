#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[5001];
int cnt[5001];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int f = 1; f <= n; f ++)
	{
		stack<int> st;
		bool vis[5001];
		memset(vis, 0, sizeof(vis));
		for(int i = f; i <= n; i ++)
		{
			if(vis[a[i]])
			{
				while(st.top() != a[i])
				{
					st.pop();
				}
			}
			else
			{
				st.push(a[i]);
				vis[a[i]] = 1;
			}
		}
		while(!st.empty())
		{
			int now = st.top();
			cnt[now] ++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i ++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
