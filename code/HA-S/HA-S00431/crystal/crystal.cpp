#include <bits/stdc++.h>
using namespace std;
long long a[200010],c[510][200010];long long n,m;bool f=0;
bool cc(long long o){
	if(f==0){
		long long e=LONG_MAX;
		for(long long g=-100;g<=100;g++){
			long long tt=1;
			long long h=min(n-o+1,tt);
			for(h;h<=n-o+1;h++){
				e=min(e,c[g+100][h+o-1]-c[g+100][h-1]);
			}
		}
		if(e<=m) return 1;
		return 0;
	}
	if(f==1&&n>5000){
		long long rr=a[2]-a[1];
		long long ccc=0;
		for(long long hh=1;hh<=o/2;hh++){
			ccc+=rr*hh;
		}
		if(o%2==0) ccc=ccc*2-o/2*rr;
		else ccc=ccc*2;
		if(ccc<=m) return 1;
		return 0;
	}
	long long w=LONG_MAX;
	long long tt=1;
	long long g=min(n-o+1,tt);
	for(g;g<=n-o+1;g++){
		long long q=(g+g+o)/2,k=0;
		q=a[q];
		for(int h=g;h<=g+o-1;h++){
			k+=abs(a[h]-q);
		}
		w=min(w,k);
	}
	if(w<=m) return 1;
	return 0; 
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long p=1;p<=n;p++){
	    cin>>a[p];
		if(a[p]>100) f=1;
	}
	sort(a+1,a+n+1);
	if(f==0){
		for(long long g=-100;g<=100;g++){
			for(long long p=1;p<=n;p++){
				c[g+100][p]=abs(a[p]-g);
				c[g+100][p]+=c[g+100][p-1];
			}
		}
	}
	long long l=1,r=n,a=1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(cc(mid)){
			l=mid+1;
			a=mid;
		}
		else r=mid-1;
	}
	cout<<a;
	return 0;
}
