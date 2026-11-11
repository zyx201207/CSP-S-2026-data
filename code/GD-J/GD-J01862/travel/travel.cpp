#include<bits/stdc++.h>
using namespace std;
bool check(char a){
	if(a=='A'||a=='B'||a=='C'){
		return 1;
	}
	else return 0;
}
bool near(char a,char b){
	if(a=='A'){
		if(b=='B')return 1;
		else return 0;
	}
	if(a=='B'){
		if(b=='A'||b=='C')return 1;
		else return 0;
	}
	if(a=='C'){
		if(b=='B')return 1;
		else return 0;
	}
	if(a=='D'){
		if(b=='F')return 1;
		else return 0;
	}
	if(a=='F'){
		if(b=='D')return 1;
		else return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<'1';
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
			return 0;
		}
		else{
			cout<<'1';
			char a=s1[2],b=s2[2];
			if((check(a)^check(b))){
				cout<<"00";
				return 0;
			}
			else{
				cout<<'1';
				if(near(a,b))cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
