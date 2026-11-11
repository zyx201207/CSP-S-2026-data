#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5,M = 3 * 1e5;
long long n,m;
long long arr[N],vis[M],cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int ok = 1;
	for(long long i = 1;i <= n;i++)
	{
		cin >> arr[i];
		if(arr[i - 1] > arr[i]) ok = 0;
	}
	if(ok)
	{
		long long j = 1;
		for(long long i = 1;i <= m;i++)
		{
			while(arr[j] <= i && j <= n) j++;
			cout << j - 1 << ' ';
		}
	}
	else
	{
		for(long long i = 1;i <= n;i++)
		{
			memset(vis,0,sizeof vis);
			for(long long j = i;j <= n;j++)
			{
				if(vis[arr[j]] != 0)
				{
					for(long long k = vis[arr[j]];k <= j;k++) vis[k] = 0;
				}
				vis[arr[j]] = j;
			}
			for(long long j = 1;j <= m;j++)
			{
//				cout << vis[j] << ' ';
				if(vis[j]) cnt[j]++;
			}
		}
		for(long long i = 1;i <= m;i++) cout << cnt[i] << ' ';
	}
	return 0;
}
