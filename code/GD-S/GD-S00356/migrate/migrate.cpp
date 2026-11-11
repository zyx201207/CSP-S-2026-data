#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define INF 0x3f3f3f3f
int n,c,t,could;
ll num[2000010];
int cnt = 0,step_min = 0;
void bfs(int u,int v,int x,int step)
{
	if(x == v)
	{
		if(step < step_min) cnt=1,step_min = step;
		else if(step == step_min) cnt++;
		return ;
	}
	if(cnt >= 3) return ;
	if(step == step_min) return ;
	int p = upper_bound(num+1,num+n+1,num[x] + could) - num - 1;
	if(p > v) p = v;
	int us = 0;
	while(p > x)
	{
		bfs(u,v,p,step+1);
		if(p == v) break;
		p--;us++;
	}
} 
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c <= 2 && c!=0)
	{
		while(t--)
		{
			int ans = 0;
			cin >> n >> could;
			for(int i = 1;i<=n;i++)cin >> num[i];
			for(int i = 1;i<=n;i++){
				for(int j = i + 1;j<=n;j++)
				{
					cnt = 0,step_min = INF;
					bfs(i,j,i,0);
					if(cnt == 2) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	while(t--)
	{
		cout << "0\n";
	}
	return 0;
 } 
