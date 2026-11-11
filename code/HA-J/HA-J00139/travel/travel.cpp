#include<bits/stdc++.h>
using namespace std;
string c1,ss1,c2,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>ss1>>c2>>ss2;
	if(c1==c2){
		cout<<"1";
		if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
			if(ss1[2]=='A'||ss1[2]=='B'||ss1[2]=='C'){
				if(ss2[2]=='A'||ss2[2]=='B'||ss2[2]=='C'){
					if(ss1[2]=='A'||ss1[2]=='C'){
			 			if(ss2[2]=='B'){
				 			cout<<"111";
						}else{
							cout<<"110";
						}
					}else if(ss1[2]=='B'){
						if(ss2[2]=='A'||ss2[2]=='c'){
							cout<<"111";
			    		}else{
							cout<<"110";
						}
					}
				}else{
					cout<<"100";
				}
			}else if(ss1[2]=='D'||ss1[2]=='E'){
				if(ss2[2]=='D'||ss2[2]=='E'){
					cout<<"111";
				}else{
					cout<<"100";
				}
			}	
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
