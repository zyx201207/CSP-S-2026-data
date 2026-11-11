#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string n1,n2;
	char m1=s1[2],m2=s2[2];
	for(int i=0;i<=1;i++){
		n1+=s1[i];
		n2+=s2[i];
	}
	if(n1==n2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((m1<='C'&&m2<='C')||(m1>='D'&&m2>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(m1-m2)==1){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
} 
