#include<bits/stdc++.h>
using namespace std;
int cx1,cx2;
string zw1,zw2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1!=cx2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(zw1[0]!=zw2[0]||zw1[1]!=zw2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((zw1[2]<='C'&&zw2[2]>='D')||(zw1[2]>='D'&&zw2[2]<='C')){
		cout<<"00";
		return 0; 
	}
	cout<<1;
	if(abs(zw1[2]-'A'-zw2[2]+'A')==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
