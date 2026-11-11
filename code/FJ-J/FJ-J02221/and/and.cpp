#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],b[20],ma=0;
int d(long long s,long long x){
	if(x==0){
		long long z=0;
		for(int i=1;i<=m;i++){
			z=z&a[i];
		} 
		ma=max(ma,z);
		return 1;
	}
	for(long long i=s;i<=n;i++){
		b[m-x+1]=a[i];
		--x;
		d(i,x);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	d(1,m);
	cout<<ma;
	return 0;
}
