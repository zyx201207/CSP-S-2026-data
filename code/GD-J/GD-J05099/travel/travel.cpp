#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout <<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout <<"1";
			int a1=s1[2]-'A';
			int a2=s2[2]-'A';
			if(a1<=2&&a2<=2||a1>=3&&a2>=3)cout <<"1";
			else cout << "0";
		}
		else {
			cout <<"00";
			int way1=(s1[0]-'0')*10+s1[1]-'0';
			int way2=(s2[0]-'0')*10+s2[1]-'0';
			if(abs(way1-way2)!=1){
				cout <<"0";
			}
			else {
				if(s1[2]==s2[2])cout << "1";
			}
			return 0;
		}
	}
	else cout << "0000";
	if(c1==c2){
		int way1=(s1[0]-'0')*10+s1[1]-'0';
		int way2=(s2[0]-'0')*10+s2[1]-'0';
	
		if(abs(way1-way2)>1){
			cout <<"0";
			//cout <<"sda";
			return 0;
		}
		else if(abs(way1-way2)==1){
			if(s1[2]!=s2[2]){
				cout <<"0";
				//cout <<"sasd";
				return 0; 
			}
			else cout <<"1";
		}
		else if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
			cout << "0";
			return 0;
		}
		else {
			if(abs(s1[2]-s2[2])==1)cout <<"1";
			else cout << "0";
		}
		
	}
	return 0;
} 
