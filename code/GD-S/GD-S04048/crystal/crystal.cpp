#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],q[1000000],xx,yy,ans;
long long zhao(long long l,long long r,long long x,long long y){
	if(l>=r) return l;
	long long mid=(l+r)/2;
	if(y*(x-mid)+q[mid]-q[x]<=m) return zhao(l,mid,x,y);
	return zhao(mid+1,r,x,y);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
		xx=zhao(0,i-1,i,a[i]);
		ans=max(ans,i-xx);
	}
	printf("%lld",ans);
	return 0;
}
