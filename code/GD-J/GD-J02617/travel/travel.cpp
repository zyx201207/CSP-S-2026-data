#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	cin>>a>>b>>a1>>b1;
	if(a!=a1){
		cout<<"0000";
	}else{
		cout<<1;
		if(b[0]+b[1]!=b1[0]+b1[1]){
			cout<<"000";
		}else{
			cout<<1;
			if((b[2]=='A'&&b1[2]=='D')||(b[2]=='B'&&b1[2]=='D')||(b[2]=='C'&&b1[2]=='D')||(b[2]=='A'&&b1[2]=='F')||(b[2]=='B'&&b1[2]=='F')||(b[2]=='C'&&b1[2]=='F')){
				cout<<"00";
			}else{
				cout<<1;
				if((b[2]=='A'&&b1[2]=='B')||(b[2]=='B'&&b1[2]=='C')||(b[2]=='D'&&b1[2]=='F')||(b1[2]=='A'&&b[2]=='B')||(b1[2]=='B'&&b[2]=='C')||(b1[2]=='D'&&b[2]=='F')){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}
