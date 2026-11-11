#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rt,Rl,Xt,Xl;
	cin>>Rt>>Rl>>Xt>>Xl;
	if(Rt!=Xt){
		cout<<"0000";
		return 0;
	}
	if(Rl[1]!=Xl[1] || Rl[0]!=Xl[0]){
		cout<<"1000";
		return 0;
	}
	if(Rl[2]=='C' && Xl[2]=='D' || Rl[2]=='D' && Xl[2]=='C'){
		cout<<"1100";
		return 0;
	}
	if(Rl[2]>'C' && Xl[2]>'C'){
		cout<<"1111"; 
		return 0;
	}
	if(abs(Rl[2]-Xl[2])==1){
		cout<<"1111";
		return 0;
	}
	cout<<"1110"; 
	return 0;
}
