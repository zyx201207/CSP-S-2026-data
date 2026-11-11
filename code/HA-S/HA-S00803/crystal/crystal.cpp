#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
bool check(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*k-(s[i]-s[i-k])<=m)return 1;
	}
	return 0;
}
#undef int
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#define int long long
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
