#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],b[N];
ll read(){
	ll s=1,l=0,t=getchar();
	while('0'>t || t>'9')
	{
	    if(t=='-') s=-1;	
	    t=getchar();
	}
	while('0'<=t && t<='9')
	{
		l=l*10+t-'0';
		t=getchar();
	}
	return l*s;
}
bool check(ll p)
{
	ll t;
	if(b[p]<=m)
	{
		return true;
	}
	t=b[p];
	for(ll i=2;i<=n-p+1;i++)
	{
		t=t-(a[i+p-2]-a[i-1])+p*(a[i+p-1]-a[i+p-2]);
		if(t<=m)
		{
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	ll l=2,r=n,mid,ans=1;
	while(r>=l)
	{	
		mid=l+(r-l)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
