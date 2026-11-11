//Trick||Treat! wo ai fentao not push_back!
#include<bits/stdc++.h>
using namespace std;
string A1,B1,A2,B2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A1>>A2>>B1>>B2;
	if(!(A1==B1)){
		cout<<"0000";
		return 0;
	}
	if(!(A2[0]==B2[0]&&A2[1]==B2[1])){
		cout<<"1000";
		return 0;
	}
	if(A2[2]=='C'){
		if(B2[2]=='B'){
			cout<<"1111";
			return 0;
		}else if(B2[2]=='A'){
			cout<<"1110";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	if(A2[2]=='A'){
		if(B2[2]=='B'){
			cout<<"1111";
			return 0;
		}else if(B2[2]=='C'){
			cout<<"1110";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	if(A2[2]=='C'){
		if(B2[2]=='B'||B2[2]=='A'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	if(A2[2]=='D'){
		if(B2[2]=='F'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	if(A2[2]=='F'){
		if(B2[2]=='D'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
} 
