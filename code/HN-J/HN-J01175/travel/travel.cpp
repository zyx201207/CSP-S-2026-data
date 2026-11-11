#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string p,q;
	for(int i=0;i<=1;i++){
		p+=s_1[i];
		q+=s_2[i];
	}
	if(q==p){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char a=s_1[2],b=s_2[2];
	int c=0,d=0;
	if((a>='A'&&a<='C')&&(b>='A'&&b<='C')){
		cout<<1;
		c=1;
	}else if((a>='D'&&a<='F')&&(b>='D'&&b<='F')){
		cout<<1;
		d=1;
	}else{
		cout<<"00";
		return 0;
	}
	if(c){
		if(abs(a-b)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(b){
		if(abs(a-b)==2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
