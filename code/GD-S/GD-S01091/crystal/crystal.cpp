#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,mx;
int a[maxn],sum[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ans=i;
		while(l<=r){
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
 } 
