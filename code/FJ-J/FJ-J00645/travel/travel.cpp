#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char cx[5],zw[5],CX[5],ZW[5];
	cin>>cx>>zw>>CX>>ZW;
	if(cx[0]==CX[0]&&cx[1]==CX[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(zw[0]==ZW[0]&&zw[1]==ZW[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(zw[2]>='A'&&zw[2]<='C'&&ZW[2]>='A'&&ZW[2]<='C'){
		cout<<"1";
	}else if(zw[2]>='D'&&zw[2]<='F'&&ZW[2]>='D'&&ZW[2]<='F'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(zw[2]+1==ZW[2]||zw[2]==ZW[2]+1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
