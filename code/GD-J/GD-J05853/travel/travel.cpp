#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sf,cf,sc,cc;
	cin>>sf>>cf>>sc>>cc;
	if(sf==sc){
		if(cf[0]==cc[0]&&cf[1]==cc[1]){
			if(cf[2]=='A'){
				if(cc[2]=='B'){
					cout<<"1111";
				}else if(cc[2]=='C'){
					cout<<"1110";
				}else{
					cout<<"1100";
				}
			}else if(cf[2]=='B'){
				if(cc[2]=='A'){
					cout<<"1111";
				}else if(cc[2]=='C'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}else if(cf[2]=='C'){
				if(cc[2]=='A'){
					cout<<"1110";
				}else if(cc[2]=='B'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}else if(cf[2]=='D'){
				if(cc[2]=='F'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}else if(cf[2]=='F'){
				if(cc[2]=='D'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
