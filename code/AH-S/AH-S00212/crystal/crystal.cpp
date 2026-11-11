#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N],n,ans,sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long i,t;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=a[2]-a[1];
	bool f=0;
	for(i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=t)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		long long cnt=0;
		for(i=n-1;i>=1;i--)
		{
			cnt=a[n]-a[i];
			if(cnt>m)
				ans=n-i;
		}
		if(ans==0)
			ans=n;
		cout<<ans;
		exit(0);
	}
	for(i=2;i<=n;i++)
	{
		long long cnt=0,j;
		for(j=i-1;j>=0;j--)
		{
			cnt+=a[i]-a[j];
			if(cnt<=m)
			{
				ans=max(ans,i-j+1);
			}
			else
				break;
		}
	}
	cout<<ans;
}/*
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}e
	sort(a+1,a+n+1);
	sum[1]=0;
	sum[2]=a[2]-a[1];
	for(i=3;i<=n;i++)
		sum[i]=sum[i-1]+a[i]-a[i-2];
	for(i=2;i<=n;i++)
		if(a[i]==a[i-1])
			sum[i]=sum[i-1];
	for(i=2;i<=n;i++)
	{o
		long long l=1,r=i;
		while(l<=r)
		{
			if(check(l,r)){
				ans=max(ans,r-l+1);
				break;
			}v
			long long mid=(l+r)/2;
			if(check(mid,r))
				l++;
			else
				l=mid+1;
		}
	}l
	cout<<ans;*/
