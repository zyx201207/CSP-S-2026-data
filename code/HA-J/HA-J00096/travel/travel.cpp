#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");

	string n,n1,a,a1;
	cin>>n>>n1>>a>>a1;
	if(n==a){
		cout<<"1111";
	}else if(n1==a1){
		cout<<"0000";
	}else if(n!=a){
		cout<"0000";
	}else{
		cout<<"1100";
	}
	return 0;
}
	

