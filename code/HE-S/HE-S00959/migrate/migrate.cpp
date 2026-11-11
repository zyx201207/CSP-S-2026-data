#include <bits/stdc++.h>
using namespace std;

const long long _2e6=2e6+50;
long long N,D,X[_2e6],ans;

long long dp[_2e6];
long long have(long long n)
{
	long long ans=0;
	if(n>=(N-1))
	{
		return 0;
	}
	if((X[n+1]-X[n])>D)
	{
		return 0;
	}
	//cout<<"dp"<<n<<":0 1 ";/////////////
	dp[n]=0;
	dp[n+1]=1;
	long long cnt=0;
	for(long long a=n+2;a<=N;a++)
	{
		if((X[a]-X[a-1])>D)
		{
			//cout<<endl;//////////////
			return ans;
		}
		dp[a]=-1;
		for(long long b=1;(b<=D)&&((a-b)>=n);b++)
		{
			//cout<<"|";////////////////
			if((dp[a]==-1)||(dp[a]>dp[a-b]))
			{
				dp[a]=dp[a-b];
				cnt=0;
			}
			else if(dp[a]==dp[a-b])
			{
				cnt++;
			}
		}
		dp[a]++;
		if(cnt==1)
		{
			ans++;
		}
		//cout<<cnt<<" ";///////////
	}
	//cout<<endl;//////////////////
	return ans;
}

int _main()
{
	cin>>N>>D;
	for(long long a=1;a<=N;a++)
	{
		cin>>X[a];
	}
	ans=0;
	for(long long a=1;a<=N;a++)
	{
		ans+=have(a);
	}
	cout<<ans<<endl;
	return 0;
}

long long T;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	for(long long a=1;a<=T;a++)
	{
		_main();
	}
	return 0;
}
