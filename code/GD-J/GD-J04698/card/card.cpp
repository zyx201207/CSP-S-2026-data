#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++)
	{
		stack<int> s;
		bool in[300005];
		while(!s.empty()) s.pop();
		memset(in, 0, sizeof(in));
		for(int j = i; j <= n; j++)
		{
			if(!in[a[j]])
			{
				s.push(a[j]);
				in[a[j]] = 1;
			}
			else
			{
				while(s.top() != a[j])
				{
					in[s.top()] = 0;
					s.pop();
				}
			}
		}
		for(int j = 1; j <= m; j++)
		{
			ans[j] += in[j];
		}
	}
	for(int i = 1; i <= m; i++) cout<<ans[i]<<' ';
	return 0;
}
