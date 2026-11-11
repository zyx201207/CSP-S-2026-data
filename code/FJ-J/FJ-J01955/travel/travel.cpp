#include<bits/stdc++.h>
using namespace std;
string c,s,C,S; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>C>>S;
	if(c==C){
		if(s[0]==S[0]&&s[1]==S[1]){
			int one=int(s[2]);
			int two=int(S[2]);
			if((one<=67&&two<=67)||(one>=68&&two>=68)){
				if(abs(one-two)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

