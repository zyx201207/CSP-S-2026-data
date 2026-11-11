#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const long long maxn = 500005;
const long long maxm = 300005;

long long n, m;

long long card[maxn];

long long next_pos[maxm];

long long oper[maxn];

long long oper_cnt[maxm], father[maxm];

std::vector <long long> son[maxm];

void dfs(long long type)
{
	if(son[type].empty())
	{
		return;
	}

	for(long long child : son[type])
	{
		dfs(child);

		oper_cnt[type] += oper_cnt[child];
	}
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	for(long long i = 1; i <= n; i++)
	{
		cin >> card[i];
	}

	next_pos[card[n]] = n;

	oper[n] = card[n];

	oper_cnt[card[n]]++;

	for(long long i = n - 1; i >= 1; i--)
	{
		if(next_pos[card[i]] == 0)
		{
			oper[i] = card[i];

			oper_cnt[card[i]]++;

			father[card[i]] = oper[i + 1];

			next_pos[card[i]] = i;

			son[oper[i + 1]].push_back(card[i]);

			continue;
		}

		oper[i] = oper[next_pos[card[i]]];

		oper_cnt[oper[i]]++;
	}

	dfs(card[n]);

	for(long long i = 1; i <= m; i++)
	{
		cout << oper_cnt[i] << " ";
	}
}
