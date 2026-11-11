#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,c2,s2;
	int t,n=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		t=n+1000;
	}else{
		t=0;
	}
	if(t==1111){
		cout<<"1111";
	}else if(t==1101){
		cout<<"1101";
	}else if(t==1110){
		cout<<"1110";
	}else if(t==1010){
		cout<<"1010";
	}else if(t==1001){
		cout<<"1001";
	}else if(t==1000){
		cout<<"1000";
	}else if(t==100){
		cout<<"0100";
	}else if(t==110){
		cout<<"0110";
	}else if(t==101){
		cout<<"0101";
	}else if(t==111){
		cout<<"0111";
	}else if(t==11){
		cout<<"0011";
	}else if(t==10){
		cout<<"0010";
	}else if(t==1){
		cout<<"0001";
	}else if(t==0){
		cout<<"0000";
	} 
	return 0;
}

