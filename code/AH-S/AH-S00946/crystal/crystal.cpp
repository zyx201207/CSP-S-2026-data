#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],dp[500005],s=0,tru=0,sum=0,ans=0;
long long minn=1000000000005,mini=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	s=a[2]-a[1];
	ans=a[1]+a[2];
	for(int i=3; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]!=s)
			tru=1;	
		ans+=a[i];		
	}
	if(tru==0)
	{
		for(int i=1; ; i++)
		{
			if(sum>m)
			{
				cout<<i-1;
				return 0;
			}
			sum+=s*i;
		}
	}
	s=0;
	ans/=n;
	for(int i=1; i<=n; i++)
	{
		if((ans-a[i])<minn&&(ans-a[i])>=0)
		{
			minn=ans-a[i];	
			mini=i;
		}	
		else if((a[i]-ans)<minn&&(ans-a[i])<=0)
		{
			minn=a[i]-ans;
			mini=i;
		}
	}
	tru=0;
	b[2]=a[2]-a[1];
	for(int i=3; i<=n; i++)
	{	tru=a[mini]-b[i-1];
		if(tru>=0)
			b[i]=max(tru,b[i-1]);
		else
			b[i]=max((0-tru),b[i-1]);
		if(b[i-1]<=m&&m<=b[i])
		{
			cout<<tru;
			return 0;
		}	
	}
	return 0;
}
