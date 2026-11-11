#include<iostream>
#include<cstring>
using namespace std;
using ll=long long;
ll a[200000+5],	max_a=-1000000;
int n,m;
bool vis[200000+5];
void dfs(ll step,ll ans)
{
	if(step==m)
	{
		max_a=max(max_a,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(step+1,ans&a[i]);
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,2147483647);
	cout<<max_a;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
