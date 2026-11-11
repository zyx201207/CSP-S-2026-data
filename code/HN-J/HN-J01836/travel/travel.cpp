#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,s1,s2;
char z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	cout<<(c1==c3);
	
	s1=c2.substr(0,2);
	s2=c4.substr(0,2);
//	cout<<s1<<" "<<s2; 
	cout<<((c1==c3)&&(s1==s2));
	
	z1=c2[2];z2=c4[2];
	if(s1==s2&&c1==c3&&((z1<='C'&&z2<='C')||(z1>='D'&&z2>='D'))){
		cout<<1;
	}else cout<<0;
	
	//cout<<z1<<" "<<z2;
	if(s1==s2&&c1==c3&&(!(z1=='C'&&z2=='D'||z1=='D'&&z2=='C'))&& (abs(z1-z2)==1||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D'))){
		cout<<1;
	}else cout<<0;
	return 0;
} 
