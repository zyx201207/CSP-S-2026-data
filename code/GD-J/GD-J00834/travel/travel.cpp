#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		if((a2[0]-'0'+a2[1]-'0')==(a4[0]-'0'+a4[1]-'0')){
			if(((a2[2]=='A')&&(a4[2]=='B'))||((a2[2]=='A')&&(a4[2]=='C'))||((a2[2]=='B')&&(a4[2]=='C'))||((a2[2]=='B')&&(a4[2]=='A'))||((a2[2]=='C')&&(a4[2]=='A'))||((a2[2]=='C')&&(a4[2]=='B'))||((a2[2]=='D')&&(a4[2]=='F'))||((a2[2]=='F')&&(a4[2]=='D'))){
				if(((a2[2]=='A')&&(a4[2]=='B'))||((a2[2]=='B')&&(a4[2]=='C'))||((a2[2]=='B')&&(a4[2]=='A'))||((a2[2]=='C')&&(a4[2]=='B'))||((a2[2]=='D')&&(a4[2]=='F'))||((a2[2]=='F')&&(a4[2]=='D'))){
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
