#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2; 
	string s1,s2;//两人的车厢和座号
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]=='D'||s1[2]=='F'){
				if(s1[2]!='D'||s1[2]!='F')cout<<"00";
				else {
					cout<<"11";
				}
			}
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]!='A'||s2[2]!='B'||s2[2]!='C')cout<<"00";
				else{
					cout<<"1";
					if(s1[2]-s2[2]==1||s2[2]-s1[1]==1)cout<<"1";
					else cout<<"0";
				} 
			}
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
