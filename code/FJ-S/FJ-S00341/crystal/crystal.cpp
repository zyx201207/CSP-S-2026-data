#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],ans;
bool chk(long long l,long long r){
	return s[r]-s[l-1]+m>=a[r]*(r-l+1);
}
long long sv(long long p){
	long long l=1,r=p,m;
	while(l<r){
		m=l+(r-l)/2;
		if(chk(m,p)){
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return p-r+1;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,sv(i));
	}
	printf("%lld",ans);
	return 0;
}
