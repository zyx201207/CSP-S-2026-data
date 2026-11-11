#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[5*100000+10],ans=1,b[5*100000+10],ok,c[5*100000+10];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		c[i]=b[i]+c[i-1];
		b[i]=b[i-1]+b[i]*(i-1);
		if(i==1)b[i]=0,c[i]=0;
	}
	long long l=1,r=2;
	while(r<=n)
	{
		if(l==r)
		{
			r++;
			continue;
		}
		long long x;
		if(l==1)x=b[r];
		else x=b[r]-b[l]-(c[r]-c[l])*(l-1);
		if(x<=m)ans=max(ans,(r-l+1)),r++;
		else l++;
	}
	cout<<ans;
	return 0;
}
