#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	int k=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}if('A'<=c2[2]&&c2[2]<='C'&&'A'<=c4[2]&&c4[2]<='C'){
		cout<<"1";
		k=1;
	}
	if('D'==c2[2]||c2[2]=='F')if('D'==c4[2]||c4[2]=='F'){
		cout<<"11";
		return 0;
	}if(k==0){
		cout<<"00";
		return 0;
	}if('B'==c2[2]||c4[2]=='B')cout<<"1";
	else{
		cout<<"0";
	}
	return 0;
}
