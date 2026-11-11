#include "bits/stdc++.h"
#define maxn 1000

int c,n,m,d,q;
int w[maxn] = {0};
int k[maxn] = {0};
int a[maxn][maxn] = {0};
int t[maxn][maxn] = {0};
int ch[maxn][maxn] = {0};

std::vector<std::pair<int,int> > plat[maxn]; // 站台 后时间 

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i = 0;i < maxn;i++)
	{
		for(int j = 0;j < maxn;j++)
		{
			ch[i][j] = INT_MAX;
		}
	}
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++)
	{
		std::cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		std::cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			std::cin >> a[i][j] >> t[i][j];
			if(!plat[a[i][j]].empty()) 
			{
				for(int k = 0;k < plat[a[i][j]].size();k++)
				{
					int l = std::min(plat[a[i][j]][k].first,i);
					int u = std::max(plat[a[i][j]][k].first,i);
					ch[l][u] = std::min(ch[l][u] , plat[a[i][j]][k].second + t[i][j]);
				}
			}
			std::pair<int,int> p(i,t[i][j]);
			plat[a[i][j]].push_back(p);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			for(int k = i + 1;k < j;k++)
			{
				ch[i][j] = std::min(ch[i][j],ch[i][k]+ch[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++)
	{
		int x,y;
		std::cin >> x >> y;
		int ans = INT_MAX;
		for(auto i : plat[x])
		{
			for(auto j : plat[y])
			{
				if(i.first == j.first)
				{
					ans = 0;
					break;
				}
				int ri = std::min(i.first,j.first);
				int rj = std::max(i.first,j.first);
				ans = std::min(ans,ch[ri][rj]);
			}
		}
		ans += w[x] + w[y];
		std::cout << ans << std::endl;
	}
	
} 
