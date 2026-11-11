#include<bits/stdc++.h>
using namespace std;
int n,d,a[2000005],sum,minn,ans;
void dfs(int step,int cnt,int flag)
{
	if(step==flag)
	{
		if(cnt<minn)
		{
			sum=1;
			minn=cnt;
		}
		else if(cnt==minn)
			sum++;
		return;
	}
	if(cnt>minn||step>n)
		return;
	for(int i=1;i<=d;i++)
	{
		for(int j=step;j<=n;j++)
			if(a[step]+i==a[j])
				dfs(j,cnt+1,flag);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		for(int j=1;j<=n;j++)
			for(int i=j+1;i<=n;i++)
			{
				sum=0;
				minn=INT_MAX;
				dfs(j,0,i);
				if(sum==2)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
