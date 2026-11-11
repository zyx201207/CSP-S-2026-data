#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
bool cmp(int x,int y){
	return x>y;
}
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		long long t=s[i+x-1]-s[i-1],des=x*a[i];
		if(des-t<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l,r,mid;
	l=1,r=n;
	while(l+1<r){
		mid=l+(r-l)/2;
		
		if(check(mid)){
			l=mid;
		}else r=mid;
	}
	printf("%lld",l);
	return 0;
}
