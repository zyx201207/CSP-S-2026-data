#include<bits/stdc++.h>
using namespace std;
long long l,r,n,m,a[500005],q[500005],etsum,lmax,lmaxsum,zt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(l=1,r=2;r<=n;)
	{
		if(etsum>m) 
		{
			etsum-=(a[r]-a[l]);	
			l++;
			continue; 
		}
		else if(etsum<=m&&zt==1) zt=0,r++;
		etsum+=(r-l)*(a[r]-a[r-1]);
		if(etsum>m) 
		{
			lmax=max(r-l,lmax);
			etsum-=(a[r]-a[l]);
			l++,zt=1;
		}
		if(zt==0) r++;
	}
	lmax=max(r-l,lmax);
	cout<<lmax;
	return 0;
}
