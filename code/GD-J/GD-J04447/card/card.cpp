#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long bj[500005];
long long ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(m<=2)
	{
		for(long long i=1;i<=n;i++) cin>>a[i];
		if(n==1)
		{
			if(a[1]==2)
			{
				cout<<"0 1";
			}
			else
			{
				cout<<"1 0";
			}
			return 0;
		}
		if(a[n]+a[n-1]==3)
		{
			if(a[n]==2)
			{
				cout<<n-1<<' '<<n;
			}
			else
			{
				cout<<n<<' '<<n-1;
			}
		}
		else if(a[n]+a[n-1]==2)
		{
			cout<<n<<' '<<0;
		}
		else
		{
			cout<<0<<' '<<n;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		memset(bj,0,sizeof(bj));
		long long t=i;
		for(long long j=i;j<=n;j++)
		{
			if(!bj[a[j]])
			{
				bj[a[j]]=1;
			}
			else
			{
				t=j;
			}
		}
		for(long long j=t;j<=n;j++)
		{
			ans[a[j]]++;
		}
	}
	for(long long i=1;i<=m;i++) cout<<ans[i]<<' ';
}
