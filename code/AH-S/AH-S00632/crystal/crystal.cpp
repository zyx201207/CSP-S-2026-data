#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int a[N];
int ans=1;
int s[N];
int n;
int m;
bool op(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int j=i+x-1;
		int sum=s[j]-s[i-1];
		if(a[j]*x-sum<=m)	return true;
	}
	return false;
}
signed  main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(op(mid))	
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else	r=mid-1;
	}
	cout<<ans<<endl;
return 0;
}
