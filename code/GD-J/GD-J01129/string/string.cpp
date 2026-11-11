#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mid,ans,a[500005],l[500005];
char c[500005];
char fd(int x){
	int L=1,R=n;
	while(L<=R){
		int m=(L+R)/2;
		if(l[m]<=x&&l[m+1]>x) return c[m];
		if(l[m]>x) R=m-1;
		else L=m+1;
	}
//	cout<<x<<" "<<L<<"\n";
	return c[L];
}
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=l[i-1]+a[i-1];
	}
	l[n+1]=l[n]+a[n];
	int L=1,R=n;
	for(L=1;;L++){
		if(l[L]>=l[n+1]/2) break;
		//L:l[L]~l[L+1]-1  R:l[n+1]-(l[L+1]-1)+1
		int r=min(l[L+1]-1,l[n+1]/2);
		while(R>=L&&l[R]>=l[n+1]-r){
			int ll1,rr1,ll2,rr2,ll,rr;
			rr1=l[n+1]-l[L]-1;
			ll1=l[n+1]-r-1;
			ll2=l[R];
			rr2=l[R+1]-1;
			ll=max(ll1,ll2);
			rr=min(rr1,rr2);
//				cout<<L<<" "<<R<<" "<<ll<<" "<<rr<<"\n";
			if(c[L]!=fd(ll)&&ll<=rr) ans+=(rr-ll+1);
			R--;
		}
		if(l[R]<=l[n+1]-r){
			int ll1,rr1,ll2,rr2,ll,rr;
			rr1=l[n+1]-l[L]-1;
			ll1=l[n+1]-r-1;
			ll2=l[R];
			rr2=l[R+1]-1;
			ll=max(ll1,ll2);
			rr=min(rr1,rr2);
//				cout<<L<<" "<<R<<" "<<ll<<" "<<rr<<"\n";
			if(c[L]!=fd(ll)&&ll<=rr) ans+=(rr-ll+1);
		}
	}
	cout<<ans;
	return 0;
}
