#include<bits/stdc++.h>
using namespace std;
int n;


struct A{
	int len;
	string letr;
}a[100005]; 
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",r,stdout);
	cin>>n;
	if(n==1){
		cout<<0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i].len>>a[i].letr;
	}
	if(n==2&&(a[0].letr!=a[1].letr)){
		cout<<min(a[1].len,a[0].len);
	}
	if(n==2&&(a[0].letr==a[1].letr)){
		cout<<0;
	}

	return 0;
}
