#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m;
int a[N],s[N];
bool check(int x){
	for(int i=x;i<=n;++i){
		if(x*a[i]-s[i]+s[i-x-1]<=m) return 1;
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}printf("%lld",l);
	
	return 0;
}
