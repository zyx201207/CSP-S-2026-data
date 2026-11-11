#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx1,cx2;
	string zw1,zw2;
	bool s=true;
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		cout<<"1";
	}
	else{
		s=false;
		cout<<"0";
	}
	if(s&&zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
		cout<<"1";
	}
	else{
		s=false;
		cout<<"0";
	}
	bool c=false;
	if(((zw1[2]=='A'||zw1[2]=='B'||zw1[2]=='C')&&(zw2[2]=='A'||zw2[2]=='B'||zw2[2]=='C'))
	||((zw1[2]=='D'||zw1[2]=='F')&&(zw2[2]=='D'||zw2[2]=='F'))) c=true;
	
	if(s&&c){
		cout<<"1";
	}
	else{
		s=false;
		cout<<"0";
	}
	c=false;
	if((zw1[2]=='A'&&zw2[2]=='B')||(zw1[2]=='B'&&(zw2[2]=='A'
	||zw2[2]=='C'))||(zw1[2]=='C'&&zw2[2]=='B')||
	(zw1[2]=='D'&&zw2[2]=='F')||(zw1[2]=='F'&&zw2[2]=='D')) 
	c=true;
	if(s&&c){
		cout<<"1";
	}
	else{
		s=false;
		cout<<"0";
	}
	return 0;
}
