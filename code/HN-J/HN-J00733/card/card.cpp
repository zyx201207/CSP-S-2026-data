#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 5e5 + 10; 
const int M = 3e5 + 10;
unordered_map<int, int> mp;
map<int, int> ans;
int table[M];
int a[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++)
	{
		//舍弃前多少张牌
		//也就是说现在是第i + 1局
		//先清空mp
		for(auto &i : mp)
		{
			i.second = 0;
		} 
		//清空桌子
		memset(table, 0, sizeof table);
		//模拟
		int idx = 0; 
		for(int j = i + 1; j <= n; j ++)
		{
			if(mp[a[j]] == 0)
			{
				//往右边甩一张 
				table[++idx] = a[j];
				mp[a[j]] = idx; 
			}
			else
			{
				//否则有出现过 
				idx = mp[a[j]] - 1;
				table[++idx] = a[j];
				//还要看右边有没有 
				for(int i = idx + 1; table[i] != 0; i ++)
				{
					mp[table[i]] = 0;
					table[i] = 0;
				}
			}
		 } 
		 //模拟完扔牌了
		//再用一个mp统计答案 
		for(int i = 1; table[i] != 0; i ++)
		{
			ans[table[i]] ++;
		}
	}
	for(auto i : ans) cout << i.second << ' ';
	return 0;
}

