#include<iostream>
#include<cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool c=0;
	if(c1!=c2){
		for(int i=1;i<=4;i++){
			cout<<0;
		}
		return 0;
	}
	else{
		cout<<1;
		c=1; 
	}
	bool d=0;
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
		d=1; 
	}
	else{
		for(int i=1;i<=3;i++){
			cout<<0;
		}
		return 0;
	}
	bool l=0;
	if(s1[2]<='C' && s2[2]<='C'){
		cout<<1;
		l=1; 
	}
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
		l=1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
