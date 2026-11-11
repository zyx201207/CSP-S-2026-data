#include<bits/stdc++.h>
using namespace std;
int main(){
	preopin("travel.in""r"std);
	preopin("travel.out""w"std);
	int C1,C2;
	string S1,S2;
	cin>>C1>>S1>>C2>>S2;
	if(C1==C2){
		cout<<"1";
		if(S1[1]==S2[1]&&S1[2]==S2[2]){
			cout<<"1";
			if(S1[3]==S2[3]){
				cout<<"1";
				
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
