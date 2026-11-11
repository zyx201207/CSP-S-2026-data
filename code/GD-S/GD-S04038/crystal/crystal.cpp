#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+50; 
long long n,m,a[N],b[N],ans,l,r,x,z,c,d;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		if(b[i]<=m)	ans=i;
		if(b[i]>m)
		{
			l=0;
			r=i;
			while(l+1<r)
        	{
    		x=(l+r)/2;
    		z=b[i]-b[x]-(x-1)*(a[i]-a[i-1]);
	    	if(z>=m) l=x;
	    	else r=x;
         	}
         	ans=max(ans,i-r+1);
		}
	}
	cout<<ans;
	return 0;
 } 


