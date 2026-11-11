#include "bits/stdc++.h"
#define maxn 100005
#define int long long

int n,M,a[maxn];
int b[maxn] = {0};
int temp;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin >> n >> M;
	for(int i = 1;i <= n;i++)
	{
		std::cin >> a[i]; 
	}
	std::sort(a+1,a+1+n);
	
	int cnt = 1;
	int temp = a[1];
	for(int i = 1;i <= n;i++)
	{
		//std::cout << temp << " " << a[i] << std::endl;
		if(temp != a[i]) b[++cnt]++,temp = a[i];
		else b[cnt]++;
	}
	
	int leng = std::unique(a+1,a+n+1)-a-1;
	int ans[maxn] = {0};
	for(int i = 1;i <= leng;i++)
	{
		int m = M;
		int l = i - 1,r = i + 1;
		while(1)
		{
			int lcost = 1 << 30,rcost = 1 << 30;
			if(l <= 0 && r > leng) break;
			if(l > 0) lcost = std::abs(a[l] - a[i]);
			if(r <= leng) rcost = std::abs(a[r] - a[i]);
//			std::cout << lcost << " " << rcost << std::endl;
//			std::cout << l << " " << r << std::endl;
			if(lcost < rcost)
			{
				int total = m/lcost;
				if(total >= b[l]) 
				{
					m -= lcost*b[l];
					ans[i] += b[l];
					l--;
				}
				else
				{
					ans[i] += total;
					break;
				}
			}
			else
			{
				int total = m/rcost;
				if(total >= b[r]) 
				{
					m -= rcost*b[r];
					ans[i] += b[r];
					r++;
				}
				else
				{
					ans[i] += total;
					break;
				} 
			}
		}
	}
	int max = -1;
//	std::cout << leng;
	for(int i = 1;i <= leng;i++)
	{
//		std::cout << b[i] << " ";
		max = std::max(max,ans[i]+b[i]); 
	}
	std::cout << max;
} 
