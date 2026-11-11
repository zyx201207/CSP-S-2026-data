#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else if(a!=c){
		cout<<0;
	}
	if(b==d){
		cout<<1;
	}
	else if(b!=d){
		cout<<0;
	}
	if(c==a){
		cout<<1;
	}
	else if(c!=a){
		cout<<0;
	}
	if(d==b){
		cout<<1;
	}
	else if(d!=b){
		cout<<0;
	} 
	return 0;
}
