#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string acar,asit,bcar,bsit;
	cin>>acar>>asit>>bcar>>bsit;
	if(acar==bcar){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(asit[0]==bsit[0]&&asit[1]==bsit[1]){
		cout<<1;
		if(asit[2]=='D'||asit[2]=='F'){
			if(bsit[2]=='D'||bsit[2]=='F'){
				cout<<11;
				return 0;
			}else{
				cout<<0;
				cout<<0;
				return 0;
			}
		}else{
			if(bsit[2]=='A'||bsit[2]=='B'||bsit[2]=='C'){
				cout<<1;
				if(abs(asit[2]-bsit[2])==1){
						cout<<1;
					}else{
						cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}
	}else{
		cout<<"000";
	}
	return 0;
} 
