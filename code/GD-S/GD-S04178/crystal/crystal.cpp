#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500005],b[500005],l=-1e12,r=1e12+1e18,midl,midr,mid,sum;
int ans,cnt,L,R,Mid,s,t;
int check(ll x) {
	cnt=0;
	for(int i=1;i<=n;i++) {
		if(a[i]<=x) {
			b[++cnt]=x-a[i];
		}
	}
	sort(b+1,b+cnt+1);
	s=0;
	for(int i=1;i<=cnt;i++) {
		if(s+b[i]<=m) s+=b[i];
		else return i-1;
	}
	return cnt;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
	}
	/*for(ll i=1;i<=20;i++) {
		cout<<check(i)<<endl;
	}
	while(r-l>=3) {
		midl=l+(r-l)/3;
		midr=r-(r-l)/3;
		//cout<<l<<" "<<r<<" "<<midl<<" "<<midr<<" "<<check(midl)<<" "<<check(midr)<<endl;
		if(check(midl)<check(midr)) {
			l=midl+1;
		}
		else {
			r=midr;
		}
	}
	
	cout<<l<<" "<<r<<endl;
	for(ll i=l;i<=r;i++) {
		ans=max(ans,check(i));
	}*/
	/*L=1,R=n;
	while(L<R) {
		Mid=L+R+1>>1;
		if(check2(Mid)) {
			L=Mid;
		}
		else {
			R=Mid-1;
		}
	}*/
	ans=1;
	sort(a+1,a+n+1);
	s=1;
	for(t=2;t<=n;t++) {
		sum+=(t-s)*(a[t]-a[t-1]);
		while(sum>m) {
			sum-=(a[t]-a[s]);
			s++;
		}
		ans=max(t-s+1,ans);
	}
	printf("%d\n",ans);
	return 0;
}
