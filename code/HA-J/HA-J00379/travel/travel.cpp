#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a1,b1;
	bool n;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]>'C'&&b2[2]>'C') n=1;
	if(a2[2]<='C'&&b2[2]<='C') n=1;
	if(a1!=b1){
		cout<<"0000"<<endl;
	}else{
		cout<<"1";
		if((a2[0]!=b2[0])||(a2[1]!=b2[1])){
			cout<<"000"<<endl;
		}else{
			cout<<"1";
			if(!n){
				cout<<"00"<<endl;
			}else{
				cout<<"1";
				if(abs(a2[2]-b2[2])==1){
					cout<<"1";
				}else cout<<"0"<<endl;
			}
		}
 	}
	return 0;
} 
