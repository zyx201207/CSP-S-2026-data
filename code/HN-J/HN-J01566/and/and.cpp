#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N],ans;
void dfs(int x,int i,int cnt)
{
	if(i>n) return;
	if(x==m)
	{
		ans=max(ans,cnt);
		return;
	}
	if(cnt==0)
	{
		dfs(1,i,a[i]);
	}
	dfs(x,i+1,cnt);
	int k=cnt&a[i+1];
	dfs(x+1,i+1,k);
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
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				int cnt=a[i]&a[j];
				ans=max(cnt,ans);
			}
		}
	}
	else dfs(0,1,0);
	cout<<ans;
	return 0;
}
