#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if((a<='C' and b<='C') or (a>'C' and b>'C')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
}
