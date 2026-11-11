#include <bits/stdc++.h> 
using namespace std;

int mi(int c){
	int x=1;
	for(int i=0; i<c; i++){
		x*=2;
	}
	return x;
}
long long yu(int a, int b){
	int d=0,c=0;
	while(a>0 && b>0){
		if(a%2==b%2)   d+=a%2*mi(c);
		a/=2,b/=2;
		c++;
	}
	return d;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin>>n>>m;
	long long a[n+10];
	long long sum=0;
	long long b[n+10];
	for(long i=0; i<n; i++){
		cin>>a[i];
	} 
	if(m==1){
		for(long long i=0; i<n; i++){
		    sum=max(sum,a[i]);
		}
	} 
	else if(m==2){
		for(long long i=0; i<n; i++){
			for(long long j=i+1; j<n; j++){
				sum=max(sum,yu(a[i],a[j]));
			}
		}
   }
   else if(m==n){
   	    for(long long i=0; i<n; i++){
			sum=yu(sum,a[i]);
		}
   }
	cout<<sum;
	return 0;
}
