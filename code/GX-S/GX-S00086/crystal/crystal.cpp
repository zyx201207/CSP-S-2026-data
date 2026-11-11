#include <bits/stdc++.h>
using namespace std;
#define lld long long
lld n,m, l,r,mid, ans;
vector<lld> a;
lld sc(lld x){
	lld L=0,R=n-1,M,P=0;
	while(L<=R){
		M=(L+R)/2;
		if(a[M]<=x) P=M,L=M+1;
		if(a[M]>x) R=M-1;
	}
	return P;
}
lld F(lld M){
	__int128 t=0;
	lld p=sc(M),c=0;
	while(p>=0){
		t+=M-a[p];
		if(t<=m){
			p--; c++;
		} else break;
	}
	return c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	lld hi=0;
	for(lld&x:a){
		cin>>x;
		hi=max(hi,(x<0?-x:x));
	}
	sort(a.begin(),a.end());
	if(hi<=40000){
		for(lld i=a[0]; i<=a[n-1]; i++){
			lld t=F(i);
			if(t>ans) ans=t;
		}
		cout<<ans<<'\n';
		return 0;
	}
	l=a[0],r=a[n-1];
	while(l<=r){
		mid=l+(r-l)/2;
		lld B=F(mid);
		if(B>=ans){
			ans=B;
			l=mid+1;
		} else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
