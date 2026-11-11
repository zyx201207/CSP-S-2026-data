#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string R1,R2,X1,X2;
	cin>>R1>>R2>>X1>>X2;
	int r1,r2,r3,x1,x2,x3;
	r1=(R1[0]-'0')*10+R1[1]-'0';
	x1=(X1[0]-'0')*10+X1[1]-'0';
	r2=(R2[0]-'0')*10+R2[1]-'0';
	x2=(X2[0]-'0')*10+X2[1]-'0';
	r3=R2[2]-'A'+1;
	x3=X2[2]-'A'+1;
	if(r1==x1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(r2==x2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if( (r3<=3&&x3<=3) || (r3>3&&x3>3)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(r3-x3==1||r3-x3==-1){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
	return 0;
}
