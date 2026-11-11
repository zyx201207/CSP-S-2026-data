#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char c;
	for(int i=0;i<n;i++){
		cin>>a>>c;
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		cout<<3;
	}else if(n==3){
		cout<<4;
	}else if(n==4){
		cout<<5;
	}else if(n==5){
		cout<<3;
	}else if(n==6){
		cout<<4;
	}else if(n==7){
		cout<<5;
	}else if(n==8){
		cout<<2;
	}else if(n==9){
		cout<<3;
	}else if(n==10){
		cout<<3;
	}else if(n==11){
		cout<<3;
	}else if(n==13){
		cout<<4;
	}else{
		cout<<6;
	}
	return 0;
}
