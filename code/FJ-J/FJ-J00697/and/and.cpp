#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long rjz(long long x){
	string y,e;
	long long z=0;
	while(x!=0){
		y[z]=x%2;
		x/=2;
		z++;
	}
	for(long long i=y.size()-1;i>=0;i--){
		e[y.size()-i]=y[i];
	}
	x=0;
	for(long long i=0;i<=e.size();i++){
		for(long long j=1;j<=i;j++){
			e[i]*=10;
		}
		x+=e[i];
	}
	return x;
}
string b;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,nm=0,nn;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a[i]=rjz(a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=j;j++){
			if(a[i]==0){
				break;
			}else if(a[i]/10==1){
				nn=0;
				while(a[i]!=0){
					a[i]/=10;
					nn++;
				}
				b[nn]=1;
				a[i]/=10;
			}else{
				a[i]/=10;
			}
		}
	}
	for(long long i=0;i<=b.size()-1;i++){
		for(long long j=1;j<=i;j++){
			b[i]*=10;
		}
		nm+=b[i];
	}
	cout<<nm;
	return 0;
}
