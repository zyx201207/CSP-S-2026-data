#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N],s[N];
bool ck(int l,int r){
	ll ans=0;
	for(int i=l+1;i<=r;i++){
		ans+=(a[i]-a[i-1])*(i-l);
		if(ans>m) return 0;
	}
	return 1;
}
int bin(int l,int r){
	int t=r;
	while(r-l>1){
		int mid=(l+r)/2;
		if(ck(mid,t)) r=mid;
		else l=mid;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	sort(a+1,a+1+n);
	int ls=1,ans=1,cnt=1;
	for(int i=2;i<=n;i++){
		ll c=s[i-1]+(a[i]-a[i-1])*(i-ls);
		if(c<=m){
			s[i]=c,cnt++;
			ans=max(ans,cnt);
			continue;
		}
		ls=bin(ls,i);
		cnt=i-ls;
		ans=max(ans,cnt); 
		for(int j=ls+1;j<=i;j++){
			s[i]+=(a[j]-a[j-1])*(j-ls);
		}
	}
	printf("%d",ans);
	return 0;
}

