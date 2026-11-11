#include<bits/stdc++.h>
using namespace std;
string a[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]='1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		a[1]='1';
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				a[2]='1';
			}
		}
		else if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F'){
				a[2]='1';
			}
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		if(s1[2]=='A'||s1[2]=='C'){
			if(s2[2]=='B'){
				cout<<"1111";
			}
			else{
				cout<<"1110";
			} 
		}
		else if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				cout<<"1111";
			}
		}
		else if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F'){
				cout<<"1111";
			}
		}
		else{
			cout<<"1110";
		}
	}
	return 0;
} 
