#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000006];
long long ans=-1e9;

void dfs(int x,int step,int cnt)
{
	cnt=cnt&a[x];
	if(step==m)
	{
		if(cnt>ans)ans=cnt;
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,step+1,cnt);
	}
}

int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;	
}
