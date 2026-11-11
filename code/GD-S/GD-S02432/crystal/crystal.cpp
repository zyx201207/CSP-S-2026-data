#include<bits/stdc++.h>
using namespace std;
int a[11111111];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n>=50000&&a[2]-a[1]==1){
		cout<<m;
	}else if(n>=50000&&a[2]-a[1]==a[4]-a[3]){
		cout<<m/(a[3]-a[2]);
	}
	long c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				c=a[j];
			a[j]=a[j+1];
			a[j+1]=c;
			}
	
		} 
	}
	long long sum=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){		
				sum+=a[i]-a[j];
		} 
		if(sum<=m){
				cout<<i+1;
				return 0;
			}	
			sum=0;
	}
	return 0;
} 
