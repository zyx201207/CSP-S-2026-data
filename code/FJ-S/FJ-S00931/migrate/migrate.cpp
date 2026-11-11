#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000010],cnt[30],n,d,minn[30],dp[2000010];
void DFS(int t,int lst,ll tmp)
{
	if(t>n)
	{
		return;
	}
	if(a[t]-a[lst]>d)
	{
		return;
	}
	DFS(t+1,lst,tmp);
	if(tmp==minn[t])
	{
		cnt[t]++;
	}
	if(tmp<minn[t])
	{
		minn[t]=tmp;
		cnt[t]=1;
	}
	DFS(t+1,t,tmp+1);
	return;
}
void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		minn[i]=2e18;
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		DFS(i,i,0);
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[j]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve2()
{
	memset(dp,0,sizeof(dp));
	if((a[2]-a[1])*2>d)
	{
		cout<<"0\n";
		return;
	}
	d-=d%(a[2]-a[1]);
	int ans=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if((a[i]-a[1])%d==0||a[i]-a[1]<=d)
		{
			dp[i]=1;
			continue;
		}
		for(ll j=d;j>=(a[i]-a[1])%d;j-=a[2]-a[1])
		{
			dp[i]+=dp[i-j/(a[2]-a[1])];
			if(dp[i]>2)
			{
				break;
			}
		}
		if(dp[i]==0)
		{
			dp[i]=1;
		}
		if(dp[i]==2)
		{
			ans+=(n-i+1);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c<3)
		{
			solve1();
		}
		else if(c==11||c==12)
		{
			solve2();
		}
	}
	return 0;
}
