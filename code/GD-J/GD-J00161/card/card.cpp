#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define ll long long
int n, m, a[N];
ll ans[N];
bool vis[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	stack<int> s;
	for(int t = 1; t <= n; t++)
	{
//		cout << t << ":\n";
		for(int i = t; i <= n; i++)
		{
			if(!vis[a[i]])
			{
				vis[a[i]] = 1;
				s.push(a[i]);
			}
			else
			{
				while(!s.empty())
				{
//					cout << s.top() << " ";
					int u = s.top();
					if(u == a[i]) break;
					else
					{
						vis[u] = 0;
						s.pop();
					}
				}
//				cout << "\n"; 
			}
		}
		while(!s.empty())
		{
//			cout << s.top() << " ";
			ans[s.top()]++;
			s.pop();
		}
//		cout << "\n";
		for(int i = 1; i <= m; i++) vis[i] = 0;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
