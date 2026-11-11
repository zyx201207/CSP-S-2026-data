#include<bits/stdc++.h>
using namespace std;
string cone,sone,ctwo,stwo;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cone>>sone>>ctwo>>stwo;
	if(sone[2]=='A'||sone[2]=='B'||sone[2]=='C'){
		a=1;
	}else if(sone[2]=='D'||sone[2]=='F'){
		a=2;
	}
	if(stwo[2]=='A'||stwo[2]=='B'||stwo[2]=='C'){
		b=1;
	}else if(stwo[2]=='D'||stwo[2]=='F'){
		b=2;
	}	
	if(cone==ctwo){
		cout<<"1";
	}else{
		cout<<"0";

	}
	if(sone[0]==stwo[0]&&sone[1]==stwo[1]&&cone==ctwo){
		cout<<"1";
	}else{
		cout<<"0";

	}
	if(sone[0]==stwo[0]&&sone[1]==stwo[1]&&cone==ctwo&&a==b){
		cout<<"1";
	}else{
		cout<<"0";

	}
	if(sone[2]>='A'&&sone[2]<='C'&&stwo[2]>='A'&&stwo[2]<='C'&&sone[0]==stwo[0]&&sone[1]==stwo[1]&&cone==ctwo&&a==b){
		if(abs(int(sone[2]-stwo[2]))==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if((sone[2]=='F'||stwo[2]=='F')&&(stwo[2]=='D'||sone[2]=='D')&&sone[0]==stwo[0]&&sone[1]==stwo[1]&&cone==ctwo&&a==b){
		cout<<"1";
	}else{
		cout<<"0"; 
	}	
	
	return 0;
} //luogu
