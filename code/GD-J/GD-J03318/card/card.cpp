#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;

int n, m, a[N], box[M];
bool vis[M];
stack<int> st;

int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		for (int j = i; j <= n; j++)
		{
			if (!vis[a[j]]) { st.push(a[j]);vis[a[j]] = 1; }
			else
			{
				int k = st.top();
				while (k != a[j])
				{
					st.pop();
					k = st.top();
				}
			}
		}
		while (!st.empty())
		{
			int k = st.top();
			box[k] ++;
			st.pop();
			cout << k << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= m; i++)
		cout << box[i] << " ";
	return 0;
 } 
 /*
10 3
3 1 2 1 3 2 3 1 2 1
*/
