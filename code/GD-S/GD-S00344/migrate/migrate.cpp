#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],dp[2000010],ans;
short kd[2000010];
inline void solve()
{
	ans=0;
	cin>>n>>d;
	for(long long i=1;i<=n;i++) cin>>x[i];
	for(long long i=1;i<=n;i++)
	{
		long long j;
		dp[i]=0;
		kd[i]=1;
		long long now=1,sum=0;
		for(j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]>d) break;
			dp[j]=1;
			kd[j]=1;
			sum++;
		}
		long long l=i+1;
		for(;j<=n;j++)
		{
			while(x[j]-x[l]>d)
			{
				sum-=kd[l];
				l++;
				if(dp[l]!=now)
				{
					now=dp[l];
					sum=kd[l];
					for(long long k=l+1;k<j;k++)
					{
						if(dp[k]!=now) break;
						sum+=kd[k];
					}
				}
			}
			if(l==j) break;
			dp[j]=dp[l]+1;
			if(sum==2) ans++;
			kd[j]=min(3ll,sum);
		}
	}
	cout<<ans<<'\n';
}
inline void solveA()
{
	ans=0;
	cin>>n>>d;
	long long l=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]-x[1]<=d) l=i-1;
	}
	if(l==1||l==0)
	{
		cout<<"0\n";
		return;
	}
	cout<<max(0ll,n-2*l+1)<<'\n';
}
inline void solveB()
{
	ans=0;
	cin>>n>>d;
	for(long long i=1;i<=n;i++) cin>>x[i];
	long long point;
	for(long long i=1;i<=n;i++)
	{
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
		{
			point=i;
			break;
		}
	}
	long long r=1,l=1;
	for(long long i=1;i<point;i++)
	{
		while(r<=n&&x[r]-x[i]<=d) r++;
		if(r>n) break;
		while(l<=n&&x[r]-x[l]>d) l++;
		while(r-l<2&&r<=n)
		{
			r++;
			while(l<=n&&x[r]-x[l]>d) l++;
		}
		if(r>n) break;
		if(r-l==2)
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--) solveA();
		return 0;
	}
	if(c==13||c==14)
	{
		while(t--) solveB();
		return 0;
	}
	while(t--) solve();
	return 0;
}
