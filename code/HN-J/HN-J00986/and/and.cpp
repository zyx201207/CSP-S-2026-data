#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn=INT_MIN;
int a[200001];
void dfs(int s,int num,int sum)
{
	if(num==m)
	{
		maxn=max(maxn,sum);
		return;
	}
	for(int i=s;i<=n;i++)
	{
		if(s==1)dfs(i+1,num+1,a[i]);
		else dfs(i+1,num+1,sum&a[i]);
	}
	
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<maxn;
	return 0;
} 
