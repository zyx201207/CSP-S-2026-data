#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000010];
int cnt1=2e6;
int ans1;
int ans;
void dfs(int x,int cnt,int v)
{
	if(x==v)
	{
		if(cnt1>cnt)
		{
			cnt1=cnt;
			ans1=1;
		}
		else if(cnt1==cnt)
		{
			ans1++;
		}
		return ;
	}
	if(x>v) return ;
	if(cnt>cnt1) return ;
	int ii=1;
	while(1)
	{
		if(a[x+ii]-a[x]>d) return ;
		dfs(x+ii,cnt+1,v);
		ii++;
	} 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans1=0;
				cnt1=2e6;
				dfs(i,0,j);
				if(ans1==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
