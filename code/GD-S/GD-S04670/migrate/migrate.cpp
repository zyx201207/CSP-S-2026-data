#include<bits/stdc++.h>
using namespace std;
long long a[3000000];
long long c,t,n,d,qq;
int hf(long long i,long long j){
	int bo=1;
	for(long long k=i;k<j;k++){
		if(a[k]+d<a[k+1])bo=0;
	}
	if(a[j-1]+d==a[j])bo=0;
	if(a[i+1]-a[i]==d)bo=0;
	return bo;
}
int dc(long long i,long long j){
	int bo=1,hd=a[i+1]-a[i];
	for(long long k=i;k<j;k++){
		if(a[k+1]-a[k]!=hd)bo=0;
	}
	
	return bo;
}
long long f(long long i){
	long long x=0;
	for(long long j=i;j<n;j++){
		if(a[j]>a[i]+d && a[j]<a[i]+2*d && j-i<=d+1 && !((j-i+1)%2==1 && dc(i,j)) && hf(i,j)){
			x+=1;
			
		}
		
	}
	return x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		qq=0;
		cin>>n>>d;
		for(long long j=0;j<n;j++){
			cin>>a[j];
		}
		for(long long j=0;j<n;j++){
			qq+=f(j);
		}
		cout<<qq<<endl;
	}
	
	return 0;
} 
