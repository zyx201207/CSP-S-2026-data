#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll a[N],sum[N],m;
int fnd(int l,int r,int x){
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(a[x]*(ll)(x-mid+1)-(sum[x]-sum[mid-1])<=m) return fnd(l,mid,x);
	return fnd(mid+1,r,x);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,i-fnd(1,i,i)+1);
	printf("%d",ans);
	return 0;
}
