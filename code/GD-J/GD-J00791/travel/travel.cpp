#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=0,a2=0,b1=0,b2=0,a3=0,b3=0;
	a1=(c1[0]-'0')*10+(c1[1]-'0');
	b1=(c2[0]-'0')*10+(c2[1]-'0');
	a2=(s1[0]-'0')*10+(s1[1]-'0');
	b2=(s2[0]-'0')*10+(s2[1]-'0');
	a3=(s1[2]-'A')+1;
	b3=(s2[2]-'A')+1;
	if(a1==b1){
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(a2==b2){
		cout<<"1";
	}
	else {
		cout<<"000";
		return 0;
	}
	if((a3+b3==10)||((a3!=4&&a3!=6)&&(b3!=4&&b3!=6))){
		cout<<"1";
	}
	else {
		cout<<"00";
		return 0;
	}
	if((a3+b3==10)||(a3==1&&b3==2)||(a3==2&&b3==3)||(a3==2&&b3==1)||(a3==3&&b3==2)){
		cout<<"1";
		return 0;
	}
	else {
		cout<<"0";
	}
	return 0;
}
