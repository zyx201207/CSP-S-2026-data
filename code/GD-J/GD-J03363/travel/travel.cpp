#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>a1>>b>>b1;
	if(a==b){
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			if(a1[2]-'A'<3&&b1[2]-'A'<3){
				if(a1[2]=='A'){
					if(b1[2]=='C'){
						cout<<"1110";
					}else{
						cout<<"1111";
					}
				}else if(a1[2]=='C'){
					if(b1[2]=='A'){
						cout<<"1110";
					}else{
						cout<<"1111";
					}
				}else{
					cout<<"1111";
				}
			}else if(a1[2]-'A'>2&&a1[2]-'A'>2){
				
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
} 
