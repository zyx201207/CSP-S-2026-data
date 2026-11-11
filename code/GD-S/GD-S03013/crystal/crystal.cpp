#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m;
ll a[N],d[N],s1[N],s2[N];
ll getv(int x,int y){
	return s1[x]-s1[x-y+1]-1ll*(x-y)*(s2[x]-s2[x-y+1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++){
		s1[i+1]=s1[i]+d[i]*i;
		s2[i+1]=s2[i]+d[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,res=1;
		while(l<=r){
			mid=(l+r)/2;
			if(getv(i,mid)<=m) res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(res,ans);
	}
	printf("%d",ans);
	return 0;
}

