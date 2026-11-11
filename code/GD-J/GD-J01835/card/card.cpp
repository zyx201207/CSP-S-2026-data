#include <bits/stdc++.h>
using namespace std;

const int N = 6 * 1e5, M = 4 * 1e5;
int n, m, a[N], dp[N], x, cur = 0, ans[N], lmn[N], rpos[M], mxid = 0;
bool hv[M], nd[M]; 
bool pf = true;
stack<long long> st;

int main()
{
	freopen("card1.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(a[i] < a[i - 1])
		{
			pf = false;
		}
	} 
	if(pf == true)
	{
		for(int i = 1; i <= m; i ++)
		{
			cout << n << " ";
		}
		return 0;
	}
	/*for(int i = cur; i >= 1; i --)
	{
		if(lmn[i] == 0)
		{
			mxid = max(mxid, i);
			hv[i] == true;
		}
		dp[lmn[i]] += dp[i];
	}*/
	for(int i = 1; i <= n; i ++)
	{
		if(hv[i] == true)
		{
			stack<long long> st;
			for(int j = 1; j <= i; j ++)
			{
				while(nd[i] != 0)
				{
					nd[st.top()] = false;
					st.pop();
				}
				st.push(i);
				nd[i] = true;
			} 
			while(st.empty())
			{
				ans[st.top()] += 1;
				st.pop();
			}
		}
	}
	for(int i = 1; i <= m; i ++)
	{
		cout << ans[i] << " ";
	}
}
