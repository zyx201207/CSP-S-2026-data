#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
long long ans;
void dfs(int x,long long cnt,int cot)
{
	if(cot>m)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(x>n)
	{
		return ;
	}
	else
	{
		dfs(x+1,cnt&a[x],cot+1);
		dfs(x+1,cnt,cot);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		dfs(1,a[i],1);
	}
	
	cout<<ans;
	return 0;
}