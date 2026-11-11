#include <bits/stdc++.h>
#define int long long
using namespace std;

int n , m;
int a[500005] , cnt[300005] , fa[300005] , faa[300005];
map<int , int>mp;
map<int , int>mp2;
bool f , vis[500005]; 

signed main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		mp2[a[i]] = i;
		if(a[i] < a[i - 1])
		{
			f = 1;
		}
	}
	for(int i = n;i >= 1;i --)
	{
		mp[a[i]] ++;
		if(mp[a[i]] == 1)
		{
			faa[a[i]] = i;
		}
		if(mp[a[i]] == 2)
		{
			fa[a[i]] = faa[a[i]];
		}
	}
	if(f == 0)
	{
		for(int i = 1;i <= m;i ++)
		{
			if(mp[i] > 1)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << mp2[i] << " ";
			}
		}	
	}
	else
	{
		for(int i = 1;i <= n;i ++)
		{
			int maxn = 0;
			memset(vis , 0 , sizeof vis);
			for(int j = i;j <= n;j ++)
			{
				if(vis[a[j]] == 1)
				{
					maxn = max(maxn , fa[a[j]]);
				}
				vis[a[j]] = 1;
			}
			int d = 1;
			maxn = max(maxn , d);
			for(int j = maxn;j <= n;j ++)
			{
				cnt[a[j]] ++;
			}
		}
		for(int i = 1;i <= m;i ++)
		{
			cout << cnt[i] << " ";
		}
	}
	return 0;
}

