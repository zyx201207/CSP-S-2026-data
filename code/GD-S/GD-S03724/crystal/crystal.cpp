#include<bits/stdc++.h>
using namespace std;
long long l,r,mid,h,k,n,m,x,ans=-1e18,a[500005],q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	q[i]=q[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		l=1,r=i-1;
		while(l<=r){
			mid=(l+r)>>1;
			k=q[i-1]-q[mid-1];
			h=a[i]*(i-mid)-k;
			if(h<=m){
				ans=max(i-mid+1,ans);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	printf("%lld",ans);
	return 0;
} 
