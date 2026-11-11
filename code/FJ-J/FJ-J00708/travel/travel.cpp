#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[5],s2[5];
	int c1,c2,a,b;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(int(s1[0])*10+s1[1]==int(s2[0])*10+s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	a=int(s1[2]-'A'+1);
	b=int(s2[2]-'A'+1);
	if(a>3&&b>3){
		cout<<1;
	}else if(a<4&&b<4){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1){
		cout<<1;
	}else{
		cout<<0;
	}
} 
