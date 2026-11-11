#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000000000000000
long long maxx1=0,a[MAXN];
unsigned long long c=1,n,m;
int main(){
	cin>>n>>m;
	a[0]=-1e176-3468679;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			c++;
		}
		else c=1;
		if(c>maxx1) maxx1=c;
		 
		
	}
	
	
	if(maxx1!=n){
		for(int i=1;i<=m;i++){
		a[0]++;
		if(a[0]>a[1]) swap(a[0],a[1]);
		if(a[i]==a[i-1]){
			c++;
		}
		else c=1;
		if(c>=maxx1) maxx1=c;
		}
	}
	
	
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			c++;
		}
		else c=1;
		if(c>=maxx1) maxx1=c;
		 
		
	}
	cout<<maxx1; 
	return 0;
} 
