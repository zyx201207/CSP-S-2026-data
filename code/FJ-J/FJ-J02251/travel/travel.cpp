#include<bits/stdc++.h>
using namespace std;
string a1,b1;
char a2[3];
char b2[3];
char a3;
char b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2[1]>>a2[2]>>a3;
	cin>>b1>>b2[1]>>b2[2]>>b3;
	if(a1==b1){
		cout<<1;
		if(a2[1]==b2[1]&&a2[2]==b2[2]){
			cout<<1;
			if(a3<='C'&&b3<='C'){
				cout<<1;
				if(a3+1==b3||a3-1==b3){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(a3>'C'&&b3>'C'){
				cout<<1;
				if(a3+1==b3||a3-1==b3){
					cout<<1;
				}else{
					cout<<0;
				}
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
