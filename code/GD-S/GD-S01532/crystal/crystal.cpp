#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;int n,m,l,r,ans,a[N];
int check(int x){
	for(int i=x;i<=n;i++){
		int cnt=0,c=1;
		for(int j=i-1;c<x;j--,c++) cnt+=a[i]-a[j];
		if(cnt<=m) return 1;
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}printf("%lld",ans);return 0;
}
