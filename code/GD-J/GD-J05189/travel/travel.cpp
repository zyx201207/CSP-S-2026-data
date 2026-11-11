#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]>='A' && s1[2]<='C' && s2[2]>='D' && s2[2]<='E'){
				cout<<"00"; 
			}
			else if(s2[2]>='A' && s2[2]<='C' && s1[2]>='D' && s1[2]<='E'){
				cout<<"00"; 
			}
			else{
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
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
	
	return 0;
} 
