#include <bits/stdc++.h>
using namespace std;
vector <long long> v;
long long c,t,n,k,x,y,sum = 1e6 + 5;
bool a[1000005];
void dfs(long long cnt)
{
	if(cnt == 0)
	{
		for(int i = 1;i <= n;i++)
		{
			long long juli = 1e6 + 5;
			for(int j = 1;j <= n;j++)
			{
				if(a[j])
				{
					juli = min(juli,abs(v[i] - v[j]));
				}
			}
			sum = max(sum,juli);
		}
		return;
	}
	long long c = cnt;
	for(int i = 1;i <= n;i++)
	{
		if(!a[i])
		{
			a[i] = 1;
			c--;
			dfs(c);
			c++;
		}
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld",&c);
	scanf("%lld",&t);
	for(int k = 1;k <= t;k++)
	{
		scanf("%lld",&n);
		scanf("%lld",&k);
		for(int i = i;i < n;i++)
		{
			scanf("%lld",&x);
			scanf("%lld",&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(k);
	}
	return 0;
}
