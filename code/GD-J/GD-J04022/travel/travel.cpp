#include <bits/stdc++.h>
using namespace std;
bool fi(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C')	return 1;
		return 0;
	}
	else if(b=='D'||b=='F')	return 1;
	return 0;
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
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!fi(s1[2],s2[2])){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(s1[2]=='D'||s1[2]=='F'){
		cout<<1;
		return 0;
	}
	else{
		if(s1[2]=='B'||s2[2]=='B'){
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	return 0;
}
