#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
ll n,m,a[N],b[N],ans,bj,s,x,c[105],d[105];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=-100&&a[i]<0) c[-a[i]]++;
		else if(a[i]<=100) d[a[i]]++;
	}	
	sort(a+1,a+n+1);
	x=a[n]-a[n-1];
	for(int i=n-1;i>=1;i--)
	{
		if(x!=a[i+1]-a[i]) bj=1;
		s+=a[n]-a[i];
		b[i]=a[i+1]-a[i]+b[i+1];
	}
	if(s<=m) {cout<<n;return 0;
	}
	if(bj==0)
	{
		ll t=0;
		for(int i=1;;i++)
		{
			t+=i*x;
			if(t>m) {cout<<i;return 0;
			}
		}
	}
	if(n<=5000)
	{
		for(ll i=n-1;i>=1;i--)
		{
			ll t=0;
			for(ll j=i;j>=1;j--)
			{
				t+=b[j]-b[i];
				if(t<=m) ans=max(ans,i-j+1);
				else break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=100;i>=-100;i--)
	{
		ll t=0,t2=0;
		for(int j=i;j>=-100;j--)
		{
			ll y;
			if(j<0) y=c[-j];
			else y=d[j];
			t+=(i-j)*y;
			if(t<=m) t2+=y,ans=max(ans,t2);
			else
			{
				t-=(i-j)*y;
				t2+=(m-t)/(i-j);
				ans=max(ans,t2);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
