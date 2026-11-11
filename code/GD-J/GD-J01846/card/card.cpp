#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, seq[N], ans[N];
int ansbak[N];
map<int, int> mp;
struct node
{
	int x;
	bool alive;
};
vector<node> v;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "r", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> seq[i];
	for(int i = 1; i <= m; i++)mp[i] = -1;
	for(int round = 1; round <= n; round++)
	{
		int len = 0;
		for(int i = round; i <= n; i++)
		{
			int cur = seq[i];
			if(mp[cur] == -1)
			{
//				cout << mp[cur] << "insert" << cur << endl;
				v.push_back({cur, 1});
				mp[cur] = v.size() - 1;
			}
			else
			{
//				cout << "delete" << cur << endl;
				int from = mp[cur] + 1;
//				cout << from << "~" << v.size() << endl;
				for(int j = from; j < v.size(); j++)
				{
					mp[v[j].x] = -1;
					v.pop_back();
				}
			}
//			for(auto i:v)
//			{
//				if(i.alive)
//				{
////					ans[i.x]++;
//					cout << i.x << ' ';
//				}
//			}
//			cout << endl;
		}
		
		for(auto i:v)
		{
			if(i.alive)
			{
				ans[i.x]++;
//				cout << i.x << ' ';
			}
		}
		
//		cout << endl;
		v.clear();
		for(int i = 1; i <= m; i++)mp[i] = -1;
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
