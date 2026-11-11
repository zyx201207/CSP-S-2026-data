#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long l=0,r=n+1,lsum=0,rsum=0;
	while(l!=r)
	{
		if(lsum==0) l++,lsum=a[l];
		if(rsum==0) r--,rsum=a[r];
		if(lsum>=rsum)
		{
			if(c[l]!=c[r]) sum+=min(rsum,lsum);
			lsum=lsum-rsum;
			rsum=0;
		}
		else if(lsum<rsum)
		{
			if(c[l]!=c[r]) sum+=lsum;
			rsum=rsum-lsum;
			lsum=0;
		}
		if(r-l==1&&lsum==rsum&&lsum==0) break;
	}
	cout<<sum<<endl;
	return 0;
}
