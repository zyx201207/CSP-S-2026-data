#include<bits/stdc++.h>
using namespace std;
long long n,m,w,siz=0;
long long l=0,r=0;
struct A{
	long long a;
	long long b; 
}ton[999999];
bool cmp(A x,A y){
	return x.a <= y.a ;
}
int X(long long x){
	for(long long i = 1 ; i <= siz ; i++ ){
		if( ton[i].a == x ) return i;
	}
	return 0;
}
int S(long long x){
	long long sum;
	for(long long i=siz;;i--){
		sum=0;
		int z=x;
		int k=i;
		bool s2=1;
		if(ton[i].b >=x){
			return 1;
		}
		while(1){
			s2=0;
			if(z>=ton[k].b ){
				z-=ton[k].b ;
				sum+=(ton[i].a - ton[k].a )*ton[k].b ;
			}
			else {
				sum+=(ton[i].a - ton[k].a )*z ;
				break;
			}
			k--;
			if(k<0) return 0; 
		}
		if(sum<=m&&s2==0) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>w;
		int s1=X(w);
		if(s1>0){
			ton[s1].b ++;
		}
		else {
			siz++;
			ton[siz].a =w;
			ton[siz].b =1;
		}
	}
	sort(ton+1,ton+siz+1,cmp);
	r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(S(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r+n%2;
	return 0;
}
