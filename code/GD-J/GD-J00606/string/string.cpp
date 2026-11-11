#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,a[N],ans,mid;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],mid+=a[i]/2;	
	int s=0,e=0;
	for(int i=1,j=n;s<mid,e>mid,i<j;i++,j--)
	{
		if(s+a[i]>=mid||e+a[j]<=mid)
		{
			if(c[i]!=c[j]) ans+=max(abs(mid-s),abs(mid-e));
			break;
		}
		if(c[i]==c[j])
		{
			ans+=abs(a[i]-a[j]);
			if(a[i]>a[j]) a[j-1]-=abs(a[i]-a[j]);
			else if(a[i]<a[j]) a[i+1]-=abs(a[i]-a[j]);
		}
		else
		{
			ans+=max(a[i],a[j]);
			if(a[i]>a[j]) a[j-1]-=abs(a[i]-a[j]);
			else if(a[i]<a[j]) a[i+1]-=abs(a[i]-a[j]);
		}
		s+=max(a[i],a[j]),e+=max(a[i],a[j]);
	}	
	cout<<ans;
	return 0;
} 
