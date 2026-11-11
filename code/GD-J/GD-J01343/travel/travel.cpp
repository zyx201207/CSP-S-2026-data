#include<bits/stdc++.h>
using namespace std;
bool f(char a,char b){
	if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
		return 1;
	}
	if((a=='D'||a=='F')&&(b=='D'||b=='F')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t;
	int x,y;
	cin>>x>>s>>y>>t;
	if(x==y){
		cout<<"1";
		if(s[0]==t[0]&&s[1]==t[1]){
			cout<<"1";
			if(f(s[2],t[2])){
				cout<<"1";
				if(abs(s[2]-t[2])==1&&(s[2]!='D'||t[2]!='F')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
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
