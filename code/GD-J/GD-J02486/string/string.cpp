#include<bits/stdc++.h>
using namespace std;
int n,num[510];
char numc[510],ind;
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		num[++ind]=a;
		numc[ind]=b;
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(numc[1]==numc[2])cout<<0;
		else cout<<min(num[1],num[2]);
	}
	return 0;
} 

