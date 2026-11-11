#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
char a[5];
char b[5];
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0; 
	}
	for(int i=0;i<3;i++){
		a[i]=c2[i];
	}
	for(int i=0;i<3;i++){
		b[i]=c4[i];
	} 
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C')){
		cout<<1;
	} 
	else{
		cout<<"00";
		return 0;
	}
	if((a[2]>b[2])&&(a[2]-b[2]==1)&&(a[2]!='D')){
		cout<<"1";
	}
	if((b[2]>a[2])&&(b[2]-a[2]==1)&&(b[2]!='D')){
		cout<<"1";
	}
	else{
		cout<<"1";
		return 0;
	}
	return 0;
}
