#include<bits/stdc++.h>
using namespace std;
int n;long long len,ans,a[200005];
map<long long,char>mp;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char y;
		cin>>a[i]>>y;
		len+=a[i];
		a[i]=len;
		mp[len]=y; 
	}
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		long long x,y;
		if(a[i]>len/2) 
		{
			ok=0;
			y=len-a[i-1];
			if(len%2) x=len-len/2;
			else x=len/2; 
		}
		else 
		{
			x=len-a[i],y=len-a[i-1];
		}
		int l=upper_bound(a+1,a+n+1,x)-a;
		int r=upper_bound(a+1,a+n+1,y)-a;
		if(l<1) l=1;
		if(x==y) r=l;
		if(r>n) r=n;
		for(int j=l;j<=r;j++)
		{
			if(mp[a[j]]!=mp[a[i]]&&a[j]<=y&&a[j-1]>=x) ans+=a[j]-a[j-1];
			else if(a[j]<=y&&mp[a[j]]!=mp[a[i]]) ans+=a[j]-x;
			else if(a[j-1]>=x&&mp[a[j]]!=mp[a[i]]) ans+=y-a[j-1];
			else if(mp[a[j]]!=mp[a[i]]) ans+=y-x;
		}
		if(ok==0) break;
	}
	cout<<ans;
	return 0;
}

