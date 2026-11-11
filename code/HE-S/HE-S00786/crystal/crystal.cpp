#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l;
int b[500005],dp[500005];
bool dengcha(long long a[],long long n){
	long long q1=0;
	q1=abs(a[1]-a[2]);
	for(long long i=3;i<=n;i++){
		if(abs(a[i]-a[i-1])!=q1){
			return 0;
		}
		else {
			q1=abs(a[i]-a[i-1]);
		}
	} 
	return 1;
}
int gongcha(long long a[],long long n){
	long long q1=0;
	q1=abs(a[1]-a[2]);
	for(long long i=3;i<=n;i++){
		if(abs(a[i]-a[i-1])!=q1){
			return 0;
		}
		else {
			q1=abs(a[i]-a[i-1]);
		}
	} 
	return q1;
}
int cnt(long long x,long long q,long long m){
	int sum=0,f=0;
	while(sum<=x){
		f++;
		sum+=q*f;
		
	}
	if(f-1<=m){
		return f-1;
	} 
	else return m;
	 
} 
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.out","w",stdout);
	 cin>>n>>m;
	 for(long long i=1;i<=n;i++){
	 	cin>>a[i];
	 	l+=a[i];
	 } 
	if(dengcha(a,n)){
		int lins=cnt(m,gongcha(a,n),n);
		cout<<lins+1;
		return 0;
	} 
	if(!(dengcha(a,n))) {
		
		for(long long i=1;i<=n;i++){
	 	b[i]=a[i];
	 }
	 sort(b+1,b+1+n);
	  for(long long i=2;i<=n;i++){
	  	for(long long j=1;j<i;j++){
	  		dp[i]+=b[i]-b[j];
		  }
	  }
	  for(long long i=1;i<=n;i++){
	  	if(dp[i+1]>m){
	  		cout<<i;
	  		return 0;
		  }
	  } 
	} 
	  
	return 0;
}
