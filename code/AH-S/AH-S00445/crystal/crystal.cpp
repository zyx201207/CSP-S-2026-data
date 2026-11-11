#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+20;
long long n,m,a[N],maxn=1,s[N];
long long max(long long a,long long b){
	if(a>b) return a;
	return b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=maxn-1;--i){
		int l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2,length=i-mid+1,c=a[i]*length-(s[i]-s[mid-1]);
			if(c<=m) {maxn=max(maxn,length);r=mid-1;}
			else l=mid+1;
		}
	}
	printf("%lld",maxn);
	return 0;
}
