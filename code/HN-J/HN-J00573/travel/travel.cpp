#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<'1';
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<'1';
	else cout<<0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'){
			if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') cout<<'1';
			else cout<<0;
		}
		if(c1[2]=='F'||c1[2]=='D'){
			if(c2[2]=='F'||c2[2]=='D') cout<<'1';
			else cout<<0;
		}
	}
	else cout<<0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(c1[2]=='A'&&c2[2]=='B'){
			cout<<'1';
			return 0;
		}
		else if(c1[2]=='B'&&c2[2]=='A'){
			cout<<'1';
			return 0;
		}
		else if(c1[2]=='C'&&c2[2]=='B'){
			cout<<'1';
			return 0;
		}
		else if(c1[2]=='B'&&c2[2]=='C'){
			cout<<'1';
			return 0;
		}
		else if(c1[2]=='D'&&c2[2]=='F'){
			cout<<'1';
			return 0;
		}
		else if(c1[2]=='F'&&c2[2]=='D'){
			cout<<'1';
			return 0;
		}
	}
	cout<<'0';
	return 0;
}
