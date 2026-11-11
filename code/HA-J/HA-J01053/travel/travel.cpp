#include <bits/stdc++.h>
using namespace std;
int main(){
	int n1,n2;
	string m1,m2;
	cin>>n1>>m1>>n2>>m2;
	if(n1==n2){
		if(m1[0]==m2[0]&&m1[1]==m2[1]){
			if(m1[2]=='A'||m1[2]=='B'||m1[2]=='C'&&m2[2]=='A'||m2[2]=='B'||m2[2]=='C'||m1[2]=='D'||m1[2]=='F'&&m2[2]=='F'||m2[2]=='D'){
				if(m1[2]=='A'&&m2[2]=='B'||m1[2]=='B'&&m2[2]=='A'||m1[2]=='B'&&m2[2]=='C'||m1[2]=='C'&&m2[2]=='B'||m1[2]=='D'&&m2[2]=='F'||m1[2]=='F'&&m2[2]=='D'){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
}
