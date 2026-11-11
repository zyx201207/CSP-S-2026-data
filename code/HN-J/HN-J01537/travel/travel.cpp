#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000";
		return 0;
	}c1=c2[0]+c2[1];
	c3=c4[0]+c4[1];
	if(c1!=c3){
		cout<<"1000";
		return 0;
	}c2=c2[2];
	c4=c4[2];
	if((c2>"C"&&c4<="C")||(c2<="C"&&c4>"C")){
		cout<<"1100";
		return 0;
	}
	if(abs(c4[0]-c2[0])==1){
		cout<<"1111";
		return 0;
	}else if((c2[0]=='D'&&c4[0]=='F')||(c2[0]=='D'&&c4[0]=='F')){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	 
	return 0;
}
