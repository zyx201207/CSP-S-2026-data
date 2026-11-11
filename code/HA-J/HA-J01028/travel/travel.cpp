#include<bits/stdc++.h>
using namespace std;
string s1,z1,s2,z2;
int f(string x,string y){
	string a=min(x,y),b=max(x,y);	
	if(a[2]=='A'&&b[2]=='B'){
		return 1;
	}
	else if(a[2]=='A'&&b[2]=='C'){
		return 1;	
	}
	else if(a[2]=='B'&&b[2]=='C'){
		return 1;
	}
	else if(a[2]=='D'&&b[2]=='F'){
		return 1;
	}
	else return 0;
}
int f1(string x,string y){
	string a=min(x,y),b=max(x,y);	
	if(a[2]=='A'&&b[2]=='B'){
		return 1;
	}
	else if(a[2]=='B'&&b[2]=='C'){
		return 1;
	}
	else if(a[2]=='D'&&b[2]=='F'){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>z1>>s2>>z2;
	if(s1==s2){
		if(z1[0]==z2[0]&&z1[1]==z2[1]){
			if(f(z1,z2)){
				if(f1(z1,z2)) cout<<"1111";
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
