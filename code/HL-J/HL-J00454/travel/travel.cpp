#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int cx1,cx2;
	cx1=(c1[0]-'0')*10+(c1[1]-'0');
	cx2=(c2[0]-'0')*10+(c2[1]-'0');
	if(cx1==cx2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	int ps1,ps2;
	ps1=(s1[0]-'0')*10+(s1[1]-'0');
	ps2=(s2[0]-'0')*10+(s2[1]-'0');
	if(ps1==ps2&&cx1==cx2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	char zw1,zw2;
	zw1=s1[2];
	zw2=s2[2];
	if((cx1==cx2&&ps1==ps2&&zw1<='C'&&zw2<='C')||(cx1==cx2&&ps1==ps2&&zw1>='D'&&zw2>='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((zw1=='C'&&zw2=='D')||(zw1=='D'&&zw2=='C')){
		cout<<"0";
	}
	else if(cx1==cx2&&ps1==ps2&&abs(int(zw1)-int(zw2))==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
