/*
*/
#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>x>>y;
	if(a!=x){
		cout<<"0000";
		return 0;
	}if(b[0]!=y[0]||b[1]!=y[1]){
		cout<<"1000";
		return 0;
	}if((b[2]<='C'&&y[2]>'C')||(b[2]>'C'&&y[2]<='C')){
		cout<<"1100";
		return 0;
	}if(abs((b[2]-'A')-(y[2]-'A'))!=1){
		cout<<"1110";
		return 0;
	}cout<<"1111";
	return 0;
} 
