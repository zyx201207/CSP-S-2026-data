#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define mp make_pair
#define ls p << 1
#define rs p << 1 | 1
typedef long long ll;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], ans[M], vis[M];
void dfs(int si)
{
	stack<int> st;
	for(int i = 1 + si; i <= n; i++)
	{
		vis[a[i]]++;
		if(vis[a[i]] == 2)
		{
			while(!st.empty() && st.top() != a[i])
			{
				vis[st.top()]--;
				st.pop();
			}
			vis[a[i]]--;
		}
		else st.push(a[i]);
	}
	while(!st.empty())
	{
		ans[st.top()]++;
		vis[st.top()]--;
		st.pop();
	}
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i <= n - 1; i++)
		dfs(i);
	for(int i = 1; i <= m; i++)
		cout << ans[i] << sp;
	return 0;
}
//O(nm): 进行m局，每次遍历n 
