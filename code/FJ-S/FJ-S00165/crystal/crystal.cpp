#include <bits/stdc++.h>
using namespace std;
long long l=0,r;
long long a,b,c[500009],d[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	r=a;
	for(long long i=1;i<=a;i++){
		cin>>c[i];
	} 
	sort(c+1,c+a+1);
	for(long long i=1;i<=a;i++){
		d[i]=d[i-1]+(i-1)*(c[i]-c[i-1]);
	}
	while((r-l)>1){
		bool k=false;
		long long m=(r+l)/2;
		for(long long i=m;i<=a;i++){
			if((d[i]-d[i-m+1])-(i-m)*(c[i]-c[i-m+1])<=b){
				k=true;
			}
		}
		if(k==true){
			l=m;
		}
		else{
			r=m;
		}
	}
	bool k=false;
	for(long long i=r;i<=a;i++){
		if((d[i]-d[i-r+1])-(i-r)*(c[i]-c[i-r+1])<=b){
			k=true;
		}
	}
	if(k) cout<<r;
	else cout<<l;
	return 0;
} 
