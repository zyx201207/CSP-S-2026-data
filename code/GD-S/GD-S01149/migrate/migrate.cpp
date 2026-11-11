#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],s;
void dfs(long long x,long long y)
{
	if(x==y)
	{
		s++;
		return ;
	}
	for(int i=x;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
		{
			dfs(a[i],y);
			if(s>2) return ;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				s=0;
				dfs(i,j);
				if(s==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
