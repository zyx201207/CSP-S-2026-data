#include<bits/stdc++.h>
using namespace std;
int c,t,n,h;
long long d,x[500],minn[500],sum[500];
void dfs(int now,int last,int p)
{
	if(minn[now]>p)
		{
			minn[now]=p;
			sum[now]=1;
		}
		else
			if(minn[now]==p)
				sum[now]++;
	if(now==h)
		return;
	if(x[now]-x[last]<=d)
		dfs(now+1,last,p);
	dfs(now+1,now,p+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		int ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				h=j;
				memset(minn,0x3f,sizeof(minn));
				memset(sum,0,sizeof(sum));
				dfs(i+1,i,0);
				if(sum[j]==2)
					ans++;
			}
		cout<<ans+1<<'\n';
	}
	return 0;
}