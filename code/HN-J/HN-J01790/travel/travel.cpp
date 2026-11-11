#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,a1,a2;
char b1,b2;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0; 
	}
	for(int i=0;i<=1;i++){
		a1+=s1[i];
		a2+=s2[i];
	}
	if(a1!=a2){
		cout<<"1000";
		return 0;
	}
	b1=s1[2];
	b2=s2[2];
	if((b1<='C'&&b2>='D')||(b1>='D'&&b2<='C')){
		cout<<"1100";
		return 0;
	}
	if(abs(b1-b2)>=2){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
