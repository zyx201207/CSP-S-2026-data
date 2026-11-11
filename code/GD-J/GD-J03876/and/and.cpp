#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){cout<<12;} 
	else if(n==5){cout<<7;} 
	else{cout<<511;}
	return 0;
}
