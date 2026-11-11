#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ispop[500005];
int last[300005];
int ans[500005];//每个牌能放几轮 
void solve1()
{
	if(m==1)
	{
		cout << n;
		return;
	}
	int other=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[n])other++;
	}
	if(a[n]==1)
	{
		cout << n << " " << other;
	}
	else cout << other << " " << n;
	return;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		last[a[i]]=i;
	}
	if(m<=2)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cout << last[i]<<" ";
	}
	return 0;
} 
