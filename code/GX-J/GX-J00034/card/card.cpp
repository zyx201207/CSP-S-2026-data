#include<bits/stdc++.h>
using namespace std;

int n, m, a[500010], ans[500010];
bool ok[300010], aok = true;
stack<int>st;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < a[i - 1])
		{
			aok = false;
		}
	}
	if(aok)
	{
		int aa = 1;
		for(int i = 1;i <= n;i++)
		{
			ans[a[i]] = aa;
			aa++;
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;j++)
			{
				//printf("%d %d\n", a[j], st.size());
				if(ok[a[j]]){
					int x = st.top();
					while(x != a[j])
					{
						st.pop();
						ok[x] = false;
						x = st.top();
					}
					ok[x] = true;
				}
				else{
					ok[a[j]] = true;
					st.push(a[j]);
				}
			}
			while(!st.empty())
			{
				int x = st.top();
				ans[x]++;
				//printf("%d\n", x);
				st.pop();
			}
			for(int x = 1;x <= m;x++)
			{
				ok[x] = false;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}
