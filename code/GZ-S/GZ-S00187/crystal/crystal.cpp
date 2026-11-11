//GZ-S00187 绥阳中学 王开润 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m;
const int N=1e5+10;
long long a[N*5];
long long b[N*5],c[N*5];
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//scanf("&lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		 scanf("%lld",&a[i]);
	 }
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0) b[i]=b[i-1]+a[i];
		else c[i]=c[i-1]+a[i];
	}  
	int j=upper_bound(a+1,a+1+n,0)-a-1;
//	cout<<i<<endl;
	int l=1,r=1;
	if(j==0) 
    {
    	while(l<=n)
    	{
    		if(m>(r-l+1)*a[r]-(c[r]-c[l-1])&&r<n) r++;
		else l++;
			ans=max(r-l+1,ans);	
		}
    	
	}
	while(l<=n)
	{
	
		if(l<j&&r<=j)
		{
			if(m>(r-l+1)*a[r]-(b[r]-b[l-1])&&r<n)
			 r++;
			else l++;ans=max(r-l+1,ans);	
		}
		else if(l<=j&&r>j)
		{
			if(m>(r-l+1)*a[r]-(b[j]-b[l-1])-(c[r]-c[j-1])&&r<n)
			 r++;
		else l++;ans=max(r-l+1,ans);	
		}
		else if(l>=j&&r>j)
		{
			if(m>(r-l+1)*a[r]-(c[r]-c[l-1])&&r<n)
			 r++;
		else l++; ans=max(ans,r-l+1);
			//ans=max(r-l+1,ans);	
		}
	}
	//	cout<<(r-l+1)*abs(a[r])-(b[r]-b[l-1])<<"   "<<l<<" "<<r<<" "<<ans<<endl;
	/**/
	cout<<ans;
	return 0;
}
