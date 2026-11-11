#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[1]==y[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((b[2]>='D'&&y[2]>='D')||(b[2]<='C'&&y[2]<='C')){
		cout<<1;	
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]>='D'&&y[2]>='D'){
		cout<<1;
	}else if(b[2]<='C'&&y[2]<='C'&&b[2]=='B'||y[2]=='B'){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
} 
