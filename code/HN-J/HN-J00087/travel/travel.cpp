#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	bool f=0;
	for(int i=0;i<2;i++){
		if(a2[i]!=b2[i]){
			f=1;
			break;
		} 
	}
	if(f==1){
		cout<<"000";
		return 0;
	}else{
		cout<<'1';
	}
	if(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'){
		cout<<'1';
		if(a2[2]-b2[2]==1||b2[2]-a2[2]==1){
			cout<<'1';
			return 0;
		}else{
			cout<<'0';
			return 0;
		}
	}else if(a2[2]>='D'&&a2[2]<='F'&&b2[2]>='D'&&b2[2]<='F'){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
