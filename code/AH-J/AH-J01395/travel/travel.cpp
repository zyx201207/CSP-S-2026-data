#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,c3,c4;
int a1,a2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>c2>>c3>>c4; 
	//---------------
	if(c1!=c3){
		cout<<"0000";
		return 0;
    }else{
    	cout<<"1"; 
	}
	//--------------- 
	for(int i=0;i<=1;i++){
		if(c2[i]!=c4[i]){
			cout<<"000";
			return 0;
		}
	} 
	cout<<"1";
	//-------------
	int flag2=0;
	a1=c2[2]-'A';
	a2=c4[2]-'A';
	if((0<=a1&&a1<=2&&0<=a2&&a2<=2)||(3<=a1&&a1<=4&&3<=a2&&a2<=4)){
		cout<<"1";
	}else{
		cout<<"0";
		flag2=1;
	}
	//-------------
	if(flag2==1){
		cout<<"0";
		return 0;
	}
	if(abs(a1-a2)<=1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0; 
} 
