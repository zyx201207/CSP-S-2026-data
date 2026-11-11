#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[0]=='0'){
		if(c1[1]==c2[1]){
			cout<<"1";
			if(s1[0]==s2[0]&&s1[0]=='0'){
				if(s1[1]==s2[1]){
					cout<<"1";
					if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
						cout<<"1";
						if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s2[2]=='C'&&s1[2]=='B')){
							cout<<"1";
						}
						else{
							cout<<"0";
							return 0;
						}
					}
					else if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
						cout<<"11";
					}
					else{
						cout<<"00";
					}
				}
				else{
					cout<<"000";
				}
			}
		}
		else{
			cout<<"0000";
			return 0;
		}
	}
	else if(c1[0]==c2[0]&&c1[0]=='1'){
		if(c1[1]==c2[1]){
			cout<<"1";
			if(s1[0]==s2[0]&&s1[0]=='1'){
				if(s1[1]==s2[1]){
					cout<<"1";
					if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
						cout<<"1";
						if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s2[2]=='C'&&s1[2]=='B')){
							cout<<"1";
						}
						else{
							cout<<"0";
							return 0;
						}
					}
					else if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
						cout<<"11";
					}
					else{
						cout<<"00";
					}
				}
				else{
					cout<<"000";
				}
			}
		}
		else{
			cout<<"0000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
