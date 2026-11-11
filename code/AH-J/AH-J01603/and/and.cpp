#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int ans;

void dfs(int f,int s,int cnt,int d)
{
	if(f==0)
	{
		ans=max(ans,cnt);
		return ;
	}
	for(int i=s+1;i<=n-f+1;++i)
	{
		if(d==1) cnt=a[i];
		dfs(f-1,i,cnt&a[i],2);
	}
}

signed main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	dfs(m,0,0,1);
	cout<<ans;
	return 0;
}
