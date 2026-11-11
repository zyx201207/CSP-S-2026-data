#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
ll a[N];
ll f[N];
ll g[N];
ll ans[N];
void one()
{
	int n;
	ll d;
	cin>>n>>d;
	bool B = 1;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(i > 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])B = 0;
	}
	if(B == 1 && n > 5000)
	{
		int cnt = 0;
		int i = 1;
		int lst = i;
		for(int j = 1;j <= n;j++)f[j] = ans[j] = g[j] = 0;
		g[f[i]] = 1 , ans[i] = 1;
		for(int j = i + 1;j <= n;j++)
		{
			while(lst < j && a[j] - a[lst] > d)g[f[lst]] -= ans[lst] , lst++;
			if(lst == j)break;
			f[j] = f[lst] + 1;
			ans[j] = g[f[lst]];
			if(ans[j] == 2)cnt += n - j + 1;
			g[f[j]] += ans[j];
		}
		cout<<cnt<<endl;
		return;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		int lst = i;
		for(int j = 1;j <= n;j++)f[j] = ans[j] = g[j] = 0;
		g[f[i]] = 1 , ans[i] = 1;
		for(int j = i + 1;j <= n;j++)
		{
			while(lst < j && a[j] - a[lst] > d)g[f[lst]] -= ans[lst] , lst++;
			if(lst == j)break;
			f[j] = f[lst] + 1;
			ans[j] = g[f[lst]];
			if(ans[j] == 2)cnt++;
			g[f[j]] += ans[j];
		}
	}
	cout<<cnt<<endl;
}
int main()
{
	freopen("migrate.in" , "r" , stdin) , freopen("migrate.out" , "w" , stdout);
	int c , t;
	cin>>c>>t;
	for(int i = 1;i <= t;i++)one();
	return 0;
}
