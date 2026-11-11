#include<bits/stdc++.h>
#define int long long
using namespace std;
string myc1,myc2,myc3,myc4;
void work(){
	cin>>myc1>>myc2>>myc3>>myc4;
	if(myc1==myc3){
		cout<<"1";
	}else{
		cout<<"0000";
		return;
	}
	int num1=(myc2[0]-'0')*10+myc2[1]-'0';
	int num2=(myc4[0]-'0')*10+myc4[1]-'0';
	if(num1==num2){
		cout<<"1";
	}else{
		cout<<"000";
		return;
	}
	if(myc2[2]=='A'||myc2[2]=='B'||myc2[2]=='C'){
		if(myc4[2]=='A'||myc4[2]=='B'||myc4[2]=='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return;
		}
	}
	if(myc2[2]=='D'||myc2[2]=='F'){
		if(myc4[2]=='D'||myc4[2]=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return;
		}
	}
	if(myc2[2]=='D'&&myc4[2]=='F'){
		cout<<"1";
		return;
	}
	if(myc2[2]=='F'&&myc4[2]=='D'){
		cout<<"1";
		return;
	}
	if(myc2[2]=='A'&&myc4[2]=='B'){
		cout<<"1";
		return;
	}
	if(myc2[2]=='B'&&myc4[2]=='A'){
		cout<<"1";
		return;
	}
	if(myc2[2]=='B'&&myc4[2]=='C'){
		cout<<"1";
		return;
	}
	if(myc2[2]=='C'&&myc4[2]=='B'){
		cout<<"1";
		return;
	}
	cout<<"0";
	return;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	work();
	return 0;
}

