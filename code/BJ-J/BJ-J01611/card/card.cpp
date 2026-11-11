#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

struct Stack
{
	int st[500001];
	int i;
	
	Stack() : i(0) {}
	
	int top() const {return st[i - 1];}
	void push(int x) {st[i++] = x;}
	void pop() {--i;}
	int size() const {return i;}
	void clear() {i = 0;}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	static int a[500001];
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	static int res[300001];
	static bitset<300001> f;
	static Stack s;
	for (int i = 1; i <= n; ++i)
	{
		f.reset();
		s.clear();
		
		for (int j = i; j <= n; ++j)
		{
			if (!f[a[j]])
			{
				s.push(a[j]);
				f[a[j]] = 1;
			}
			else
			{
				int x;
				while ((x = s.top()) != a[j])
				{
					f[x] = 0;
					s.pop();
				}
			}
		}
		
		while (s.size())
		{
			++res[s.top()];
			s.pop();
		}
	}
	
	for (int i = 1; i <= m; ++i) cout << res[i] << ' ';
	cout << '\n';
	
	return 0;
}
