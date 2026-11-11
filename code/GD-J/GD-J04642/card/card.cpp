#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m;
int a[N],cnt[N];
bool flag = 1,vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] < a[i - 1])
			flag = 0;
	}
	if(flag)
	{
		int kk = 0;
		for(int i = n;i >= 1;i--)
		{
			cnt[a[i]] = n + i - n;
			if(a[i] == a[i - 1])
			{
				kk = i;
				break;
			}
		}
		for(int i = 1;i <= m;i++)
		{
			cout << cnt[i] << " ";
		}
		return 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;j++)
			{
				if(!vis[a[j]])
					vis[a[j]] = 1;
				else
				{
					for(int k = j - 1;k >= i;k--)
					{
						if(a[k] == a[j])
							break;
						vis[a[k]] = 0;
					}
				}
			}
			for(int j = 1;j <= m;j++)
				cnt[j] += vis[j];
			memset(vis,0,sizeof(vis));
		}
		for(int i = 1;i <= m;i++)
			cout << cnt[i] << " ";
	}
	return 0;
}

