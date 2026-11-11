#include<bits/stdc++.h>
using namespace std;
string cx1,zw1,cx2,zw2;
int cxx1,ps1;
char zm1;
int cxx2,ps2;
char zm2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	for(int i=0;i<cx1.size();i++){
		int zh=cx1[i]-48;
		cxx1=cxx1*10+zh;
	}
	for(int i=0;i<zw1.size()-1;i++){
		int zh=zw1[i]-48;
		ps1=ps1*10+zh;
	}
	zm1=zw1[zw1.size()-1];
	for(int i=0;i<cx2.size();i++){
		int zh=cx2[i]-48;
		cxx2=cxx2*10+zh;
	}
	for(int i=0;i<zw2.size()-1;i++){
		int zh=zw2[i]-48;
		ps2=ps2*10+zh;
	}
	zm2=zw2[zw2.size()-1];
	if(cxx1==cxx2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(ps1==ps2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(zm1>='A'&&zm1<='C'){
		if(zm2>='A'&&zm2<='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(zm2=='D'||zm2=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(zm1>='A'&&zm1<='C'){
		if(abs(zm1-zm2)==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"1";
	}
return 0;
}
