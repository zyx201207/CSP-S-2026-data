#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200005];
int vis[200005];
int ans;
int n,m;
void dfs(int x,int cnt)
{
	if(x > m)
	{
		ans = max(ans,cnt);
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			dfs(x+1,cnt&a[i]);
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cout<<log2(31);
	bool flag = true;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		int cmp = log2(a[i]);
		cmp++;
		if((1 << cmp) -1 != a[i])
			flag = false;
	}
	if(flag)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			vis[i] = 1;
			dfs(2,a[i]);
			vis[i] = 0;
		}
		cout<<ans;
	}
	return 0;
}
