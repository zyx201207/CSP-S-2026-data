#include<bits/stdc++.h>
using namespace std;
string s1,a1;
string s2,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a1;
	cin>>s2>>a2;
	if(s1==s2){
		cout<<'1';
		if(a1[0]==a2[0]&&a1[1]==a2[1]){
			cout<<'1';
			if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')){
				cout<<'1';
				if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='C')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
			else if((a1[2]=='D'&&a2[2]=='F')||(a1[2]=='F'&&a2[2]=='D')){
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
