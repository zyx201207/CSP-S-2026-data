#include<bits/stdc++.h>
using namespace std;//Trick||Treat! travel
long long a[10000005];
long long n,m;
long long l,r;
int sb(long long a,long long b){
	return a&b;
}
int SB(long long s){
	long long y=s;
	s=0;
	for(long long i=1;i<=n;i++){
		s=max(s,sb(a[i],y));
		if(s==sb(a[i],y)){
			l=a[i];
		}
	}
	a[l]=0;
	return s;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0;
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			s=max(s,sb(a[i],a[j]));
			if(s==sb(a[i],a[j])){
				l=a[i];
				r=a[j];
			}
		}
	}
	a[l]=0;
	a[r]=0;
	if(m>2){
		m=m-2
		while(m--){
			s=SB(s);
		}
	}
	cout<<s;
	return 0;
} 
