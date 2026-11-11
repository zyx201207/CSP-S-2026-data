#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],l=1,r=1,ans=1,cost=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		r++;
		cost+=(a[i]-a[i-1])*(r-l);
		while(cost>m&&l<r)
		{
			cost=cost-(a[i]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
