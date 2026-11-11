#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<' '<<s1<<' '<<c2<<' '<<s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<'1';
		if(s2[0]==s1[0]&&s1[1]==s2[1]){
			cout<<'1';
			if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')){
				cout<<"11";
			}
			if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
				cout<<"10";
			}
			if((s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')){
				cout<<"11";
			}
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"00";
				}
			}
			if(s2[2]=='D'||s2[2]=='F'){
				if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
					cout<<"00";
				}
			}
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='F')){
				cout<<"11";
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
