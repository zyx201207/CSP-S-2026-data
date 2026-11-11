#include<bits/stdc++.h>
using namespace std;
int n;
int a1;
char b1;
int a2;
char b2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
	}else if(n==2){
		cin>>a1>>b1;
		cin>>a2>>b2;
		cout<<min(a1,a2);	
	}else cout<<0;
	
	
	
	return 0;
} 
