#include <bits/stdc++.h>
#define N 500010
using namespace std;
int n,m,a[N],pre[N];
stack<int> st;
vector<int> ans[N];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin >> n >> m;
	memset (pre,-1,sizeof pre);
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 1;i <= n;++i)
	{
		for (int j = i - 1;j >= 1;--j)
			if (a[i] == a[j])
			{
				pre[i] = j;
				break;
			}
	}
	for (int i = 1;i <= n;++i)
	{
		for (int j = i;j <= n;++j)
		{
			if (pre[j] != -1 && pre[j] >= i)
			{
				while (st.top() != j && st.empty()) st.pop();
			}
			st.push(j);
		}
		while (!st.empty())
		{
			ans[st.top()].push_back(i);
			st.pop();
		}
	}
	for (int i = 1;i <= m;++i) cout << (int)ans[i].size() << " ";
	return 0;
}

