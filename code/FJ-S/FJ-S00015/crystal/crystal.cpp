#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N],dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	bool f=1;
	bool fb=1;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)f=0;
	}
	long long cha=a[n]-a[n-1];
	for(int i=n;i>=2;i--)
	{
		if(a[i]-a[i-1]!=cha)fb=0;
	}
	if(m==0)
	{
		long long maxx=0;
		dp[1]=1;
		sort(a+1,a+1+n);
		bool ff=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])ff=1;
		}
		if(ff==0)
		{
			cout<<0;
			return 0;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])dp[i]=dp[i-1]+1;
			else dp[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,dp[i]);
		}
		cout<<maxx;
	}
	else if(f==1)
	{
		long long cnt=0;
		long long k=1;
		while(m>=0)
		{
			m-=k;
			k++;
			cnt++;
		}
		if(cnt>n)cout<<n;
		else cout<<cnt;
	}
	else if(fb==1)
	{
		long long cnt=0;
		long long k=cha;
		while(m>=0)
		{
			m-=k;
			k+=cha;
			cnt++;
		}
		if(cnt>n)cout<<n;
		else cout<<cnt;
	}
	else 
	{
		
		long long maxx=-114514;
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		{
			long long mm=m;
			for(int j=1;j<i;j++)
			{
				dp[j]=a[i]-a[j];
			}
			
			long long cnt=0;
			for(int j=i-1;j>=1;j--)
			{
				//cout<<dp[j]<<" ";
				mm-=dp[j];
				if(mm<0)break;
				cnt++;
				if(cnt>=n)
				{
					cout<<n;
					return 0;
				}
			}
			maxx=max(maxx,cnt);
		}
		if(maxx==0)cout<<0;
		else cout<<maxx+1;
	}
	return 0;
}
