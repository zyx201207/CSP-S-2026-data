#include<bits/stdc++.h>

#define int long long 
#define N 200010

using namespace std;

int n, m;
int a[N];
int last[N]; // 表示上一次这张牌出现的位置
int ans[N];
//int c[N]; // 表示当前牌堆 
bool f[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(last, 0, sizeof(last));
		memset(f, false, sizeof(f));
//		memset(c, 0, sizeof(c));
		stack<int> st;
		for (int j = i; j <= n; j++)
		{
			st.push(a[j]);
			if (f[a[j]] == false)
			{
				f[a[j]] = true;
			}
			else
			{
				st.pop();
				while(st.top() != a[j])
				{
					f[st.top()] = false;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}	
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
