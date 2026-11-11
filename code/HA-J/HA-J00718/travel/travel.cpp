#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		cout<<1;
		if(a2[0]==a4[0] and a2[1]==a4[1]){
			cout<<1;
			if(a2[2]=='A'){
				if(a4[2]=='B' or a4[2]=='C'){
					cout<<1;
					if(a4[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				} 
				else{
					cout<<"00";
				}
			} 
			if(a2[2]=='B'){
				if(a4[2]=='A' or a4[2]=='C'){
					cout<<"11";
				} 
				else{
					cout<<"00";
				}
			}
			if(a2[2]=='C'){
				if(a4[2]=='B' or a4[2]=='A'){
					cout<<1;
					if(a4[2]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				} 
				else{
					cout<<"00"; 
				}
			} 
			if(a2[2]=='D'){
				if(a4[2]=='F'){
					cout<<"11";
				} 
				else{
					cout<<"00"; 
				}
			} 
			if(a2[2]=='F'){
				if(a4[2]=='D'){
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
