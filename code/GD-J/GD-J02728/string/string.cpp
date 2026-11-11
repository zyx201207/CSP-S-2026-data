#include<bits/stdc++.h>
using namespace std;
char a[1000000005];
long long o(long long l,long long r){
	long long s=0;
	while(l<r){
		if(a[l]!=a[r]){
			l++;
			s++;
		}
		else{
			break;
		}
	}
	if(l==r) return r-l;
	return s;
}
long long j(long long l,long long r){
	long long s=0;
	while(l<r){
		if(a[l]!=a[r]){
			r--;
			s++;
		}
		else{
			break;
		}
	}
	if(l==r) return r-l;
	return s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long q;
	cin>>q;
	long long w;
	long long m=0;
	
	int p=0;
	while(q--){
		cin>>w;
		char z;
		cin>>z;
		
		for(int i=p;i<w+p;i++){
			a[i]==z;
		}
	}
	long long l,r;
	l=0;
	r=p-1;
	while(l<r){
		long long ma,mi;
		if(a[l]!=a[r]){
			ma=o(l,r);
			mi=j(l,r);
			if(ma>mi){
				r-=mi;
				m++;
			}
			else{
				l+=ma;
				m++;
			}
		}
	}
	cout<<m;
	return 0;
}

