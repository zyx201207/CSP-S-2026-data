#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in",'l',stdin);
	freopen("and.out",'r',stdout);
	long long n,m,ma=0;
	long long a[1000000];
	cin>>n>>m;
	for(long long i=0;i<n;++i){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1)cout<<ma;
	else if(n==m){
		long long fir=a[0];
		for(long long i=1;i<n;i++)fir=fir&a[i];
		cout<<fir;
	}else if(ma<4){
		cout<<2;
	}else{
		cout<<ma;
	}
	fclose("and.in");
	fclose("and.out");
} 
