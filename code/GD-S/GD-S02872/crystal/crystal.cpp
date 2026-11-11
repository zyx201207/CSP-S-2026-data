#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,a[500005],s=0,res=0;
inline ll read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll bs(ll l,ll r){
	while(l<r){
		ll mid=(l+r)/2;
		if(a[mid]<=s) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		s+=a[i];
	}
	s/=n;
	sort(a+1,a+n+1);
	res=bs(1,n);
	printf("%lld",res);
	return 0;
}
