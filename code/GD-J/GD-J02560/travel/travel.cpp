#include<bits/stdc++.h>
using namespace std;

int a1,b1;
string a2,b2;
bool a=0,b=0,c=0,d=0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		d=1;
	}
	if(d){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		a=1;
	}
	if(a&&d){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((a2[2]>='A'&&a2[2]<='C')&&(b2[2]>='A'&&b2[2]<='C'))||((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'&&b2[2]=='F'))){
		b=1;
	}
	if(a&&b&&d){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')||(a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='B')){
		c=1;
	}
	if(a&&b&&c&&d){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
