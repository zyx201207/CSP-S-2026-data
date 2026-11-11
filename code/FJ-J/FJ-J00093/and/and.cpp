#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int cnt[40];
int sorted[40];
struct Node
{
	int num, key;
	
	bool operator<(const Node &T) const
	{
		return key > T.key;
	}
} seq[N];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i )
	{
		cin >> seq[i].num;
		
		int tmp = seq[i].num, idx = 0;
		while (tmp)
		{
			cnt[idx ++ ] += tmp % 2;
			tmp /= 2;
		}
	}
	
	for (int i = 31; i >= 0; -- i )
		if (cnt[i] >= m) sorted[ ++ sorted[0] ] = i;
	
	for (int i = 1; i <= n; ++ i )
	{
		for (int j = 1; j <= sorted[0]; ++ j )
			seq[i].key += ((seq[i].num >> (sorted[j])) & 1) * (1 << (sorted[j]));
	}
	
	sort(seq + 1, seq + 1 + n);
	
	int res = seq[1].num;
	for (int i = 2; i <= m; ++ i )
		res &= seq[i].num;
		
	cout << res << "\n";
	
//	for (int i = 1; i <= sorted[0]; ++ i )
//		cout << sorted[i] << " ";
	
	return 0;
}
