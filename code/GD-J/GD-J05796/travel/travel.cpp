#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1[10],s1[10],c2[10],s2[10];
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		int n=(s1[0]-'0')*10+(s1[1]-'0');
		int m=(s2[0]-'0')*10+(s2[1]-'0');
		if(n==m){
			cout<<"1";
			int a=s1[2]-'A',b=s2[2]-'A';
			if(a<3&&b<3||a>2&&b>2){
				cout<<"1";
				if(a-b==1||b-a==1){
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
} 
