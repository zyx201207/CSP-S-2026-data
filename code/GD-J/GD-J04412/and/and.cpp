#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
const int N = 2e5+5;
int n, m;
int a[N];
vector<int> re[40];
vector<int> num;
int vis[N];
int main()
{
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
	scanf("%d%d",&n, &m);
	For(i, 1, n)
	{
		scanf("%d",&a[i]);
		int tmp = a[i], cnt = 0;
		while(tmp)
		{
			if(tmp&1) re[cnt].push_back(i);
			tmp >>= 1;
			cnt++;
		}
	}
	RFor(i, 35, 0)
	{
		if((int)re[i].size() >= m)
		{
			if(num.empty()) num = re[i];
			else
			{
				memset(vis, 0, sizeof vis);
				for(int j:num)
					vis[j]++;
				for(int j:re[i])
					vis[j]++;
				int he = 0;
				For(i, 1, n)
					he += (vis[i] == 2);
				if(he >= m)
				{
					num.clear();
					For(i, 1, n) if(vis[i] == 2)
						num.push_back(i);
				}
			}
		}
//		printf("%d size:%d\n",i, num.size());
//		for(int j:num)
//			printf("%d ",j);
//		printf("\n");
		if((int)num.size() == m)
		{
			ll ans = (1ll<<31)-1;
			for(int j:num)
				ans &= a[j];
			printf("%lld",ans);
			return 0;
		}
	}
	if((int)num.size() > m)
	{
		ll ans = (1ll<<31)-1;
		for(int j:num)
			ans &= a[j];
		printf("%lld",ans);
	}
	else printf("0");
	return 0;
}
/*
5 3
31 3 1 15 7
*/
//	For(i, 0, 35)
//	{
//		printf("%d size:%d\n",i, re[i].size());
//		for(int j:re[i])
//			printf("%d ",j);
//		printf("\n");
//	}
