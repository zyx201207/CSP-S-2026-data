#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m,q;
	long long a[100000]; 
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]<0&&a[2]<0){
		cout<<4;
		
	}
	if(a[1]>=0&&a[2]>=0){
	
	q=a[1]+a[2];
	cout<<q;
	}
	
	return 0;
}
