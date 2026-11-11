#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a1,a2;
	string b1,b2;
	if(!(cin>>a1>>b1>>a2>>b2)) return 0;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b1[0]!=b2[0]||b1[1]!=b2[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((b1[2]-'A')/3!=(b2[2]-'A')/3){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if((abs(b1[2]-b2[2])!=1||(b1[2]=='C'&&b2[2]=='D')||(b2[2]=='C'&&b1[2]=='D'))&&!((b2[2]=='F'&&b1[2]=='D')||(b2[2]=='D'&&b1[2]=='F'))){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	
	fclose(stdout);
	return 0;
}
