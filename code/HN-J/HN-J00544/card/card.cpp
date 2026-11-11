#include <bits/stdc++.h>
using namespace std;
int a[500001] = {};
int cnt[300001] = {};
bool f[300001] = {};
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			f[j] = 0;
		}
		for(int j = i;j <= n;j ++)
		{
			st.push(a[j]);
			if(f[a[j]])
			{
				st.pop();
				while(st.top() != a[j] || st.empty())
				{
					st.pop();
				}
			}
			else
			{
				f[a[j]] = 1;
			}
		}
		while(!st.empty())
		{
			cnt[st.top()] ++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i ++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}

