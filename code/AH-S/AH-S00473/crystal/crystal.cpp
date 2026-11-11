#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
int n,m;
int a[N],a1[N],a2[N];

bool check(int len)
{
	long long sum=0;
	for(int i=1;i<len;i++) sum+=a[i]*i;
	if(sum<=m) return true;
	for(int i=len+1;i<n;i++)
	{
		sum-=(a1[i-1]-a1[i-len-1]);
		sum+=len*a[i];
		if(sum<=m) return true;
	}	
	return false;
}	


int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],a1[i]=a1[i-1]+a[i];

	for(int i=1;i<n;i++) a2[i]=a[i+1]-a[i];
	
	int l,r;
	l=1,r=n;

	while(l<r-1)
	{
		
		
		
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}		
	if(check(r)) cout<<r;
	else cout<<l;
	 
	 return 0;
}	
