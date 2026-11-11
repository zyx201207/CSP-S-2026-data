#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int a=(sr[0]-'0')*10+sr[1]-'0';
	int b=(sx[0]-'0')*10+sx[1]-'0';
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char n=sr[2],m=sx[2];
	if((n<='C'&&m<='C')||(n>='D'&&m>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int c=abs(int(n-m));
	if(c==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
