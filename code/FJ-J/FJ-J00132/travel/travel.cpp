#include<bits/stdc++.h>
using namespace std;
int main(){
	string rc;
	string rd;
	string xc;
	string xd;
	cin>>rc>>rd>>xc>>xd;
	if(rc==xc){
		
		if(rd[0]==xd[0]&&rd[1]==xd[1]){
			
			if((rd[2]-'A')>(xd[2]-'A')){
				if((rd[2]=='F'&&xd[2]=='D')||(rd[2]=='C'&&xd[2]=='B')||(rd[2]=='C'&&xd[2]=='A')||(rd[2]=='B'&&xd[2]=='A')){
					
					if((rd[2]-'A')-(xd[2]-'A')==1&&rd[2]!='D'&&xd[2]!='C'){
						cout<<"1111";
					}
					else{
						cout<<"1110";
					}
				}
				else{
					cout<<"1100";
				}
			}
			else{
				if((rd[2]-'A')<(xd[2]-'A')){
					if((rd[2]=='D'&&xd[2]=='F')||(rd[2]=='B'&&xd[2]=='C')||(rd[2]=='A'&&xd[2]=='C')||(rd[2]=='A'&&xd[2]=='B')){
						if((xd[2]-'A')-(rd[2]-'A')==1&&rd[2]!='C'&&xd[2]!='D'){
							cout<<"1111";
						}
						else{
							cout<<"1110";
						}
					}
					else{
						cout<<"1100";
					}
				}
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
