#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long
using namespace std;
int d[500005];
int cnt[300005];
bool used[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&d[i]);
	int use = 1;
	for (int i = 1;i <= n;i++)
	{
		vector <int > card;
		memset(used,0,sizeof(used));
		for (int j = use;j <= n;j++)
		{
			int p = -1;
			for (int k = 0;k < (int)card.size();k++)
				if (card[k] == d[i])
					p = k;
			if (p != -1)
			{
				vector <int > t(card.begin() + p,card.end());
				card.clear();
				for (auto & k : t)
					card.push_back(k);
			}
			card.push_back(d[j]);
		}
		use++;
		for (auto & j : card)
		{
			if (!used[j])
			{
				cnt[j]++;
				used[j] = true;
			}
		}
	}
	for (int i = 1;i <= m;i++)
		printf("%lld ",cnt[i]);
	return 0;
}
