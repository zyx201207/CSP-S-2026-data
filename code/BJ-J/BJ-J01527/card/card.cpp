//48pts
#include <bits/stdc++.h>
using namespace std;

int n,m,a[5010],h[3010],ans[3010];
stack <int> s;

int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) scanf("%d" , &a[i]);
	for (int i = 1;i <= n;i ++)
	{
		while (s.size()) s.pop();
		memset(h , 0 , sizeof(h));
		for (int j = i;j <= n;j ++)
		{
			if (h[a[j]])
				while (s.top() != a[j])
				{
					h[s.top()] --;
					s.pop();
				}
			else
			{
				s.push(a[j]);
				h[a[j]] ++;
			}
		}
		for (int i = 1;i <= m;i ++) if (h[i]) ans[i] ++;
	}
	for (int i = 1;i <= m;i ++) printf("%d " , ans[i]);
	return 0;
}