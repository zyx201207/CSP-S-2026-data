#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],s[N],m;
bool check(int k) {
	for(int i=1;i+k-1<=n;i++) {
		if(a[i+k-1]*k-(s[i+k-1]-s[i-1])<=m) return true;
	}
	return false;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<=r) {
    	int mid=(l+r)>>1;
    	if(check(mid)) l=mid+1;
    	else r=mid-1;
	}
	int ans=0;
	for(int i=max(l-100,1);i<=min(l+100,n);i++) {
		if(check(i)) ans=i;
	}
	printf("%d",ans);
	return 0;
}

