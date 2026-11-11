#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans=-1e9;
long long a[N];
long long t(long long n){//十进制转二进制 
	string s;
	while(n!=0){
		s+=((n%2)+'0');
		n/=2;
	}
	long long x=0;
	for(long long i=s.size()-1;i>=0;i--){
		x*=10;
		x+=(s[i]-'0');
	}
	return x;
}
long long sx(long long n){//二进制转十进制 
	long long sum=0;
	long long t=1;
	while(n!=0){
		if(n%10==1){
			sum+=t;
		}
		t*=2;
		n/=10;
	}
	return sum;
}
long long xand(long long a,long long b){
	long long x=t(a),y=t(b);
	string s;
	while(x!=0 && y!=0){
		if(x%10 && y%10){
			s+=('1');
		}else{
			s+=('0');
		}
		x/=10;
		y/=10;
	}
	long long n=0;
	for(long long i=s.size()-1;i>=0;i--){
		n*=10;
		n+=s[i]-'0';
	}
	return sx(n);
}
void sum(long long i,long long x,long long f){
	if(f==m){
		ans=max(ans,x);
		return;
	}
	for(long long j=1;j<=n-i;j++){
		long long s=xand(x,a[i+j]);
		f++;
		sum(i+j,s,f);
		f--;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		sum(i,a[i],1);
	}
	cout <<ans;
	return 0;
}
