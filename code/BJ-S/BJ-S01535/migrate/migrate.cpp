#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

int n, d;
int a[2000001];

struct BFS
{
	int id, v, rev;
};

void upsd(vector<int>& x, int a, int b)
{
	for (int i = a, j = b; i < j; ++i, --j)
	{
		swap(x[i], x[j]);
	}
}

vector<int> bfs(int fm, int to)
{
	static bitset<2000001> f;
	queue<BFS> q;
	
	static int rev[2000001];
	
	f.reset();
	q.push({fm, 0, -1});
	
	while (!q.empty())
	{
		BFS x = q.front();
		q.pop();
		
		if (f[x.id]) continue;
		f[x.id] = 1;
		
		rev[x.id] = x.rev;
		
		if (x.id == to) break;
		
		for (int i = x.id + 1; i <= n && a[i] - a[x.id] <= d; ++i)
		{
			q.push({i, x.v + 1, x.id});
		}
	}
	
	vector<int> res;
	int id = to;
	while (id != -1)
	{
		res.push_back(id);
		id = rev[id];
	}
	upsd(res, 0, res.size() - 1);
	
	return res;
}

bool dfs_main(vector<int>& rte, int id, int to, int lmt, const vector<int>& fbd1, const vector<int>& fbd2)
{
	if (id == to)
	{
		if (lmt == 0)
		{
			rte.push_back(id);
			
			if (rte != fbd1 && rte != fbd2) return true;
			else
			{
				rte.resize(rte.size() - 1);
				return false;
			}
		}
		else return false;
	}
	
	if (lmt == 0) return false;
	
	rte.push_back(id);
	
	for (int i = id + 1; i <= n && a[i] - a[id] <= d; ++i)
	{
		if (dfs_main(rte, i, to, lmt - 1, fbd1, fbd2)) return true;
	}
	
	rte.resize(rte.size() - 1);
	return false;
}

vector<int> dfs1(int fm, int to, int lmt, const vector<int>& fbd)
{
	vector<int> res;
	dfs_main(res, fm, to, lmt, fbd, {});
	return res;
}

bool dfs2(int fm, int to, int lmt, const vector<int>& fbd1, const vector<int>& fbd2)
{
	vector<int> rte;
	return dfs_main(rte, fm, to, lmt, fbd1, fbd2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		
		unsigned long long res = 0;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				const vector<int> fs = bfs(i, j);
				const vector<int> fs2 = dfs1(i, j, fs.size() - 1, fs);
				
				if (fs.size() == fs2.size())
				{
					if (!dfs2(i, j, fs.size() - 1, fs, fs2))
					{
						++res;
					}
				}
			}
		}
		
		cout << res << '\n';
	}
	
	return 0;
}
