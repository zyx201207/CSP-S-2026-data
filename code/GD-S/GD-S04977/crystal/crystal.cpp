#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],s[500100];
long long ans=1;

long long find(long long x)
{
	long long l=1,r=x,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if( (a[x]*(x-mid+1)) - (s[x]-s[mid-1]) <= m )
			r = mid;
		else
			l = mid+1;
	}
	return l;
}

int main()
{
	ios::sync_with_stdio(false);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i] = s[i-1] + a[i];
	
	for(int i=1;i<=n;i++)
		ans = max(ans,i-find(i)+1);
	
	cout<<ans;
	
	return 0;
} 
