#include<iostream>
using namespace std;
int main(){
	int y=0,x=0,z=0;
	char a[5],b[5],c[5],d[5];
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if((a[0]-'0')*10+(a[1]-'0')==(c[0]-'0')*10+(c[1]-'0')){
		cout<<"1";
		
	}else{
		cout<<"0";
		x=1;
	}
	if(x==0){
	
		if((b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')){
			cout<<"1";
			y++;
		}
	} else{
		cout<<"0"; 
	}
	if(y==0){
		cout<<"0";
	}else{
		if(b[2]<='C' and d[2]<='C'  or  b[2]>'C' and d[2]>'C'){
			cout<<"1";
			z=1;
		}
	}
	if(x==1){
		cout<<"0";
	}else if(z==1 and  ((b[2]=='B' or d[2]=='B') )   or b[2]>'C'){
		cout<<"1";
	}else if(b[2]==d[2]  and ((b[0]-'0')*10+(b[1]-'0')-(d[0]-'0')*10-(d[1]-'0')==1 or (b[0]-'0')*10+(b[1]-'0')-(d[0]-'0')*10-(d[1]-'0')==-1)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
