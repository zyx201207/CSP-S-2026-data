#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,x2,y,y2;
	cin>>x>>x2>>y>>y2;
	if(x==y) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	} 
	if(x==y && x2[1]==y2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(x2[2]<='C' && y2[2]<='C' ||x2[2]>'C' && y2[2]>'C') cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(x2[2]-y2[2])==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
