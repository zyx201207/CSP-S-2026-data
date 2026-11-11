#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char a3,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==b1 && a2==b2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==b2 && a2==b2 && (a3>'C' && b3>'C') || ((a3<='C' && b3<='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==b2 && a2==b2 && (a3>'C' && b3>'C') || 
	  (a3<='C' && b3<='C') && (abs(a2-b2)<=1 && abs(a3-b3)<=1)){
	  	cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
