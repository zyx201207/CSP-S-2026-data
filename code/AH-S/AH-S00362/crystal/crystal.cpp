#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
long long n,m,a[N],ans,le,ri;
long long f(long long k){
	le=1,ri=n;
	long long mi;
	while(le<ri-1){
		mi=(le+ri)>>1;
		if(k==a[mi])return mi;
		if(k>a[mi])le=mi;
		else ri=mi;
	}
	return le;
}
long long sum(long long l,long long r,long long mid){
	long long mm=m,s=0,ad=f(mid);
	int zt=1;
	for(int i=ad;i>=1;i--){
		if(mid-a[i]<=mm)s++,mm-=mid-a[i];
		else{
			zt=0;
			break;
		}
	}
	for(int i=ad+1;i<=n;i++){
		if(a[i]==mid)s++;
		else break;
	}
	if(l+1<r&&!zt)return max(s,max(sum(l,mid,(l+mid)>>1),sum(mid,r,(mid+r)>>1)));
	else if(l+1<r)return max(s,sum(mid,r,(mid+r)>>1));
	else return s;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long l=a[1],r=a[n];
	long long mid=(l+r)>>1;
	ans=sum(l,r,mid);
	long long s=1;
	for(int i=n-1;i>=1;i--){
		if(a[n]-a[i]<=m)s++,m-=a[n]-a[i];
		else break;
	}
	printf("%lld",max(ans,s));
	return 0;
}
