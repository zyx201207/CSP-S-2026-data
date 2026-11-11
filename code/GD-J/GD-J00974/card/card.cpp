#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans[N], inq[N];stack<int> Q;
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			if(inq[a[j]] == 1)
			{
				while(Q.top() != a[j])
				{
					inq[Q.top()] = 0;
					Q.pop();
				}
				Q.pop();
				Q.push(a[j]);
			}
			else
			{
				inq[a[j]] = 1;
				Q.push(a[j]);
			}
		}
		while(!Q.empty())
		{
			ans[Q.top()] ++;
			inq[Q.top()] = 0;
			Q.pop();
		}
	}
	for(int i = 1;i <= m;i ++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}

