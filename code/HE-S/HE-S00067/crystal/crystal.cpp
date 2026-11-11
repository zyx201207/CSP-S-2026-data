#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e18;
ll n,m,a[500005],ans=0;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll nk=n;
	while(nk>ans)
	{   //cout<<nk<<" ";
		if(nk!=n&&a[nk]==a[nk+1])
		{
			nk--;
			continue;
		}
		ll mk=m,nj=nk,re=0;
		while(nj>=1&&mk>=a[nk]-a[nj])
		{
			mk-=a[nk]-a[nj];
			nj--;
			re++;
		}
		ans=max(ans,re);
		nk--;
	}
	printf("%lld",ans);
	return 0;
} 

//bool check(ll x)
//{
//	ll ct=lower_bound(a+1,a+1+n,x)-a;
//	
//}
//	ll l=0,r=N+1;
//	while(l<r)
//	{
//		ll mid=(l+r)>>1;
//		if(check(mid)) l=mid;
//		else r=mid-1;
//	}
// -Wall -Wextra -Wshadow
