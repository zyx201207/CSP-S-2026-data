#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 3e5+10;
int n,m;
int a[N];
int cnt[M];
bool vis[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	stack<int> st;
	for (int k = 1;k<=n;k++)
	{
		for (int i = k;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				st.push(a[i]);
				vis[a[i]] = 1;
			}
			else
			{
				while(!st.empty() && st.top()!=a[i])
				{
					vis[st.top()] = 0;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			vis[st.top()] = 0;
			cnt[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1;i<=m;i++)
	{
		printf("%d ",cnt[i]);
	}
	return 0;
}
