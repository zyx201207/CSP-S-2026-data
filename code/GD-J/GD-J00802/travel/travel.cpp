#include<bits/stdc++.h>
using namespace std;
string a,a2,b,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a2>>b>>b2;
	if(a==b){
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<1;
			if(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'){
				cout<<1;
				if((a2[2]=='A'&&b2[2]=='C')|(b2[2]=='A'&&a2[2]=='C')){
					cout<<0;
				}else{
					cout<<1;
				}
			}else if((a2[2]=='D'&&b2[2]=='F')|(b2[2]=='D'&&a2[2]=='F')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
