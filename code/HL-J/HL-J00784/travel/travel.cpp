#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int Rc,Xc;
	string Rx,Xx;
	cin>>Rc>>Rx>>Xc>>Xx;
	if(Rc==Xc){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(Rx[0]==Xx[0]&&Rx[1]==Xx[1]){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(Rx[2]-'0'<20&&Xx[2]-'0'<20){
		cout<<1;
		if(Rx[2]-'0'==18||Xx[2]-'0'==18){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(Rx[2]-'0'>19&&Xx[2]-'0'>19){
		cout<<11;
	}
	else{
		cout<<0;
		cout<<0;
	}
	return 0;
}