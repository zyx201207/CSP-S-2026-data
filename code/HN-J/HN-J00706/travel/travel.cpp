#include<bits/stdc++.h>

using namespace std;

string a,b,c,d;

int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin>>a>>b>>c>>d;

	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0; 
	}//1
	
	char a1=b[0],a2=b[1],a3=d[0],a4=d[1];
	char b1=b[2],b2=d[2];
	
	if(a1==a3 and a2==a4){
		cout<<1;
	}else{
		cout<<0;
	}//2
	int ab=0;
	if(a1==a3 and a2==a4){
		if(b1<='C' and b2<='C'){
			cout<<1;
			ab=1;
		}
		else if(b1>'C' and b2>'C'){
			cout<<1;
			ab=1;
		}else{
			cout<<0;
		}
	}//3
	else{
		cout<<0;
	}
	
	if(ab==1){
		if(b1>'C'){
			cout<<1;
		}else if(b1+'1'-'0'==b2 or b1+'2'-'3'==b1){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0;
} 
