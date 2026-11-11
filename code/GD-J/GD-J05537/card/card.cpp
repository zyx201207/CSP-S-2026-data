#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;

const int N = 5e5+5;
const int M = 3e5+5;
int a[N];
int ans[M]; 
int vis[M];
int del[N];
int n,m;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(del,0,sizeof(del));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]] && del[vis[a[j]]]==0)
			{
				for(int k=vis[a[j]];k<j;k++)
				{
					del[k] = 1;
				}
			}
			vis[a[j]] = j;
		}
		for(int j = i;j<=n;j++)
		{
			if(del[j]==0) ans[a[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
