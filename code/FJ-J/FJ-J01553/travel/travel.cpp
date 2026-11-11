#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cs1,cs2,cp1,cp2;
	cin>>cs1>>cp1>>cs2>>cp2;
	if(cs1==cs2){
		cout<<"1";
		if(cp1[0]==cp2[0]&&cp1[1]==cp2[1]){
			cout<<"1";
			if(cp1[2]=='A'||cp1[2]=='B'||cp1[2]=='C'){
				if(cp2[2]=='A'||cp2[2]=='B'||cp2[2]=='C'){
					cout<<"1";
					
				}else{
					cout<<"00";
					return 0;
				}
				
			}else{
				if(cp2[2]=='D'||cp2[2]=='F'){
					cout<<"1";
					
				}else{
					cout<<"00";
					return 0;
				}
			}
			if(cp1[2]==cp2[2]+1||cp1[2]==cp2[2]-1){
						cout<<"1";
			}else{
				cout<<"0";
			}
			
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	
	
	
	
	return 0;
}
