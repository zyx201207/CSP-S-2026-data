#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=ll>T read(T&&x=T()){
	x=0;int fg=1;
	char c=gc();
	while(!isdigit(c))
		fg-=(c=='-')<<1,c=gc();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=gc();
	return x*=fg;
}
const int N=5e5+5;
ll a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n=read(),m=read();
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
	auto check=[&](int x){
		ll sum=0,l=1,r=0;
		// if(x==5000)cout<<x<<endl;
		for(int i=1;i<=n;i++){
			if(i>1)sum+=(a[i]-a[i-1])*(i-l-(r-i+1));
			while(r-l+1<x){
				r++;
				sum+=a[r]-a[i];
			}
			while(r<i){
				r++;
				sum+=a[r]-a[i];
				sum-=a[i]-a[l];
				l++;
			}
			// if(x==5000)cout<<i<<' '<<l<<' '<<r<<' '<<sum<<endl;
			if(r==i&&sum<=m)return 1;
		}
		return 0;
	};
	int l=1,r=n;
	while(l<r){
		int mid=(l+r>>1)+1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	// ll sm=0;
	// for(int i=1;i<=n;i++){
	// 	sm+=abs(a[i]-a[1467]);
	// }
	// cout<<sm<<endl;
}