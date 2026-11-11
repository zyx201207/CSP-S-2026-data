#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n,m;
int a[N];
int cnt[N],vis[N],c[N];
int fl1 = 1,fl2 = 1;
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		int now = 0;
		for(int j=1;j<=m;j++) vis[j] = 0;
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				c[++now] = a[j];
				vis[a[j]] = 1;
			}
			else
			{
				while(c[now] != a[j])
				{
					vis[c[now]] = 0;
					now--;
				}
			}
		}
		for(int j=1;j<=now;j++)
		{
			cnt[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout << cnt[i] << ' ';
}
void solve2()
{
	int p = a[n];
	cnt[p] = n;
	for(int i=1;i<n;i++)
	{
		if(a[i] != p) cnt[a[i]] ++;
	}
	for(int i=1;i<=m;i++) cout << cnt[i] << ' ';
}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++) cnt[i] = cnt[i-1] + vis[i];
	for(int i=1;i<=m;i++) cout << cnt[i] << ' ';
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] > a[i-1] && i!= 1) fl1 = 0; 
	}
	if(n <= 5000) solve1();
	else if(m == 2) solve2();
	else if(fl1) solve3();
	return 0;
}
