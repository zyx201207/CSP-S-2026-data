#include<bits/stdc++.h>
using namespace std;
int main(){
	char b,d,e;
	int a,c;
	cin>>a>>b>>c>>d;
	e=d-b;
	if(a!=c){
		cout<<"0000";
	}
	if(a==c){
		cout<<"1";
		if(e==1){
			cout<<"111";
		}else{
			cout<<"001";
		}
	}
	return 0;
} 
