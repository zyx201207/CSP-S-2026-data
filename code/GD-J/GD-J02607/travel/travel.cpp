#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int main(){
	ifstream("D:\GD-J02607\travel\travel.in");
	ofstream("D:\GD-J02607\travel\travel.out");
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<'1';
				if(abs(s1[2]-s2[2])==1)cout<<'1';
				else cout<<'0';
			}
			else{
				if(s1[2]>'C'&&s2[2]>'C'){
					cout<<'1';
					if(abs(s1[2]-s2[2])==1)cout<<'1';
					else cout<<'0';
				}
				else{
					cout<<"00";
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
}
