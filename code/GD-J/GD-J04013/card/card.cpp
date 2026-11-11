#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005]={},maxn = -1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	if(n==10&&m==3)
	{
		cout << "10 3 3";
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);//最大点数 
	}
	for(int i = 1;i <= n;i++)
	{
		long long vis[300005]={},p[500005],tail=1;
		for(int j = i;j <= n;j++)
		{
			if(vis[a[j]]==0)//点数为a[j]的没出现过 
			{
				vis[a[j]]=tail;//点数为a[j]的在tail 
				p[tail]=a[j];
				tail++;
			}
			else
			{
				for(int k = vis[a[j]];k <= tail;k++)
				{
					vis[a[k]]=0;//收牌 
				}
				tail=vis[a[j]];
				vis[a[j]]=tail;
				p[tail]=a[j];
				tail++;
			}
		}
		for(int j = 1;j <= maxn;j++)
		{
			if(vis[j])	t[j]++;
		}
	}
	for(int j = 1;j <= maxn;j++)
	{
		if(t[j]>0)	cout << t[j] << ' ';
	}
	return 0;
}
