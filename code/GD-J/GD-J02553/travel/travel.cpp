#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool t1=0,t2=0,t3=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
		t1=1;
	}
	else cout<<"0";
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&t1==1){
		cout<<"1";
		t2=1;
	}
	else cout<<"0";
	bool tac=s1[2]<='C'&&s1[2]>='A' && s2[2]<='C'&&s2[2]>='A';
	bool tde=s1[2]<='E'&&s1[2]>='D' && s2[2]<='E'&&s2[2]>='D';
	if( ( tac==1 || tde==1 ) && t2==1 ){
		cout<<"1";
		t3=1;
	}
	else cout<<"0";
	if( ( (s1[2]<='E'&&s1[2]>='D') && (s2[2]<='E'&&s2[2]>='D') ) &&t3==1 ) cout<<"1";
	else if(s1[2]=='A'&&s2[2]=='B'&&t3==1) cout<<"1";
	else if(s1[2]=='B'&&t3==1) cout<<"1";
	else if(s1[2]=='C'&&s2[2]=='B'&&t3==1) cout<<"1";
	else cout<<"0";
	
	return 0;
}
