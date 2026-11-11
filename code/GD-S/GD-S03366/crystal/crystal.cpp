#include<bits/stdc++.h>
using namespace std;
long long n,m,b[500010];
long long a[500010],s;
long long ef(long long x)
{
	long long l=0,r=n+1;
	while(l+1<r)
	{
		long long mid=(l+r)/2;
		long long len=(x-mid+1);
		if((a[x]*len)-(b[x]-b[mid-1])<=m)
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		s=max(s,i-ef(i)+1ll);
	}
	cout<<s;
	return 0;
} 
