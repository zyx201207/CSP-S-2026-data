#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[200005][35];
ll b[200005];
bool vis[200005];
void solve()
{
	ll n,m;
	cin >> n >> m;
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	for(int i = 1;i <= n;i++)
	{
		ll x;
		cin >> x;
		b[i] = x;
		ll r = 31;
		while(x)
		{
			a[i][r] = x%2;
			r--;
			x/=2;
		}
	}
	ll r = 0;
	for(int i = 1;i <= 31;i++)
	{
		
		ll cnt = 0;
		ll cnt1 = 0;
		for(int j = 1;j <= n;j++)
		{
			if(vis[j] == 0)
			{
				cnt1++;
			}
			if(a[j][i] == 1 && vis[j] == 0)
			{
				cnt++;
			}
		} 
		if(cnt1 < m)
		{
			r = r*2;
			continue;
		}
		if(cnt < m)
		{
			r = r*2;
			continue;
		}
		r = r*2+1;
		for(int j = 1;j <= n;j++)
		{
			if(!(a[j][i]))
			{
				vis[j] = 1;
			}
		} 
	}
	
	cout << r << endl;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	solve();
	return 0;
}
