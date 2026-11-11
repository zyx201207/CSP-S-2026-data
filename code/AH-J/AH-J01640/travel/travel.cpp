#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	if(a[0]!=a[2]){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	char f=a[1][0],g=a[1][1],h=a[3][0],l=a[3][1];
	if(f==h&&g==l){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(abs(a[1][2]-a[3][2])<=2&&a[1][2]!='D'&&a[1][2]!='E'&&a[3][2]!='D'&&a[3][2]!='E'){
		cout<<"1";	
	}else if(abs(a[1][2]-a[3][2])<=1&&(a[1][2]=='D'||a[1][2]=='E')&&(a[3][2]=='D'||a[3][2]=='E')){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(a[1][2]-a[3][2])<=1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
} 
