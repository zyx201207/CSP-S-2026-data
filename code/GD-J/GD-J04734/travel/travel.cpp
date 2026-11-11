#include<bits/stdc++.h>
using namespace std;
string rc,rw,xc,xw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rw>>xc>>xw;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	if(rw[0]!=xw[0]||rw[1]!=xw[1]){
		cout<<"1000";
		return 0;
	}
	if(!((rw[2]>='D'&&xw[2]>='D')||(rw[2]<='C'&&xw[2]<='C'))){
		cout<<"1100";
		return 0;
	}
	if(rw[2]+1==xw[2]||xw[2]+1==rw[2]){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
