#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N];
int last[N];
int tmp[N];
int ans[N];
template <typename T>
struct Stack {
private:
	T s[N];
	size_t end;
public:
	Stack() : end(0) {}
	void push(T x) { s[end++] = x; }
	T top() { return s[end - 1]; }
	size_t size() { return end; }
	void pop(int x = 1) { end -= x; }
	void pop_index(int x) { end = x; }
	int count(T target)
	{
		int res = 0;
		for (int i = 1; i < (int)end; ++i)
			if (s[i] == target)
				++res;
		return res;
	}
};
Stack<int> stk;

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int k = 1; k <= n; ++k)
	{
		
		for (int i = k; i <= n; ++i)
		{
			if (tmp[a[i]]) stk.pop_index(tmp[a[i]]);
			stk.push(a[i]);
			tmp[a[i]] = i;
		}
		for (int i = k; i <= n; ++i)
			if (!last[a[i]])
				last[a[i]] = 1, ans[a[i]] += stk.count(a[i]);
		
		memset(tmp, 0, sizeof tmp);
		memset(last, 0, sizeof last);
		stk = Stack<int>();
	}
	for (int i = 1; i <= m; ++i)
		printf("%d ", ans[i] + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

