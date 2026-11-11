#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1){
		cout<<1;
		return 0;
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l,r,mid,ok=1;
		l=1,r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*a[i]-b[i]+b[i-mid]<=m){
				ok=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,ok);
	}
	cout<<ans;
}
