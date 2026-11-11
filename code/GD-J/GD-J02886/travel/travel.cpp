#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=false;
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		if(c2[1]==c4[1]){
			cout<<1;
			if(c2[2]=='A' or c2[2]=='B' or c2[2]=='C'){
				if(c4[2]=='A' or c4[2]=='B' or c4[2]=='C'){
					f=true;
					cout<<1;
					if(int(c2[2])+1==int(c4[2]) or int(c2[2])-1==int(c4[2])){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0;
				}
			}
			else{
				if(c4[2]=='D' or c4[2]=='F'){
					f=true;
					cout<<1;
					if(int(c2[2])+1==int(c4[2]) or int(c2[2])-1==int(c4[2])){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0;
				}
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"000";
	}
	if(!f){
		cout<<0;
	}
	return 0;
} 
