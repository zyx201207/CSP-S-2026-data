#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
void nx(){
	if(abs(s1[2]-s2[2])==1&&((s1[2]!='D'&&s2[2]!='C')&&(s1[2]!='C'&&s2[2]!='D'))){
		cout<<1;
	}
	else cout<<0;
}
void sd(){
	if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E'))){
		cout<<1;
		nx();
	}
	else cout<<"00";
}
void ln(){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		sd();
	}
	else cout<<"000";
}
void cx(){
	if(c1==c2){
		cout<<1;
		ln();
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cx();
	return 0;
}
