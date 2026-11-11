#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans;
int a[200010],n,m;
void dfs(int i,int w,int sum)
{
	if(w==m)
	{
		ans=max(ans,sum);
		return ;
	}
	if(w>m)return;
	if(i>n) return;
	if(sum==-1) dfs(i+1,w+1,a[i]);
	else dfs(i+1,w+1,sum&a[i]);
	dfs(i+1,w,sum);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}
