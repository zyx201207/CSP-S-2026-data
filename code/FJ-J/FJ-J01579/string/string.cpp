#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
int sum[200005];
int n,h;
bool check(int lim)
{
	return sum[lim]>=h;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s=s+a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0,x=1;
	for(int i=1;x<=s/2;)
	{
		int l=1,r=n;
		h=s+1-x;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1; 
		}
		if((h-sum[l-1])>=sum[i]-x+1)
		{
			if(c[i]!=c[l])ans+=sum[i]-x+1;
			x+=sum[i]-x+1,i++;
		}
		else 
		{
			x+=(h-sum[l-1]);
			if(c[i]!=c[l])ans+=(h-sum[l-1]);
		}
	}
	cout<<ans;
	return 0;
}

