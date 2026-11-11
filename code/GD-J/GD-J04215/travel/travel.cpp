#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char z1=s1[2];
	char z2=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	
	int a=(s1[0]-'0')+(s1[1]-'0');
	int b=(s2[0]-'0')+(s2[1]-'0');
	//Í¬Ò»ÅÅ 
	if(a==b) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	//²¢ÅÅ 
	if((z1=='A')&&(z2=='B')){
		cout<<"11";
	}
	else if((z1=='A')&&(z2=='C')) cout<<"10";
	else if((z1=='B')&&(z2=='C')) cout<<"11";
	else if((z1=='B')&&(z2=='A')) cout<<"11";
	else if((z1=='C')&&(z2=='A')) cout<<"10";
	else if((z1=='C')&&(z2=='B')) cout<<"11";
	else if((z1=='D'&&z2=='F')||(z2=='D'&&z1=='F')) cout<<"11";
	else cout<<"00"; 
	return 0;
} 
