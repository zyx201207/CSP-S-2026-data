#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char bb=b[2],dd=d[2];
	long long b1=(b[0]-'0')*10+(b[1]-'0'),d1=(d[0]-'0')*10+(d[1]-'0');
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b1==d1){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	bool x=0;
	if((bb>'C'&&dd>'C')||(bb<='C'&&dd<='C')){
		x=1;
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(x==1){
		if((bb-'A')-(dd-'A')==1||(dd-'A')-(bb-'A')==1){
			cout<<"1";
		}else{
			cout<<"0";
		}	
	}
	return 0;
} 
