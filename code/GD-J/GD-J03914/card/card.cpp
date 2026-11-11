#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100010],vis[100010],dis[100010];
void f(int x)
{
	memset(vis,0,sizeof(vis));
	long long d[100010],cnt = 0;
	for(long long i = x ; i <= n ; i ++)
	{
		bool flag = false;
		long long num = 0;
		for(long long j = i ; j >= 1 ; j --) if(d[j] == a[i]) 
		{
			flag = true;
			num = j;
			break;
		}
		if(flag) 
		{
			for(long long j = num ; j <= i ; j ++) 
			{
				vis[d[j]] --;
				d[j] = 0;
			}
			cnt = num -1;
		}
		d[++cnt] = a[i];
		vis[a[i]] ++;
	}
	for(long long i = 1 ; i <= m ; i ++) if(vis[i] != 0) dis[i] ++;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i ++) cin >> a[i];
	for(long long i = 1 ; i <= n ; i ++) f(i);
	for(long long i = 1 ; i <= m ; i ++) cout << dis[i] << " ";
}
