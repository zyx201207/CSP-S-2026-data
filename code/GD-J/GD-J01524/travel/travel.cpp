#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string R1,R2,X1,X2;
inline void solve(){
	cin>>R1>>R2>>X1>>X2;
	if(R1==X1){
		cout<<"1";
		if(R2[0]==X2[0]&&R2[1]==X2[1]){
			cout<<"1";
			if(R2[2]=='A'){
				if(X2[2]=='B'||X2[2]=='C'){
					cout<<"1";
					if(X2[2]=='B'){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			if(R2[2]=='B'){
				if(X2[2]=='A'||X2[2]=='C'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			if(R2[2]=='C'){
				if(X2[2]=='B'||X2[2]=='A'){
					cout<<"1";
					if(X2[2]=='B'){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			if(R2[2]=='D'){
				if(X2[2]=='F'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			if(R2[2]=='F'){
				if(X2[2]=='D'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
		} 
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
} 
int main(){
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}
