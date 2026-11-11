#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,minv[2000005],num[2000005],a[2000005],ans;
void dfs(int x,int y)
{
	if(minv[x]>y)minv[x]=y,num[x]=1;
	else if(minv[x]==y)num[x]++;
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]<=m)
		{
			dfs(i,y+1);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int k=i;k<=n;k++)minv[k]=0x3f3f3f3f3f3f3f3f;
			dfs(i,0);
			for(int k=i+1;k<=n;k++)if(num[k]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
