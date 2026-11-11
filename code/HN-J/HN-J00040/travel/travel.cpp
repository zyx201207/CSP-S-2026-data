#include<bits/stdc++.h>
using namespace std;
char s1[4],s2[4];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
	}
	else cout<<"0";
	if(c1==c2&&s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<"1";
	}
	else cout<<"0";
	if(c1==c2&&s1[1]==s2[1]&&s1[2]==s2[2]&&(s1[3]=='A'&&(s2[3]=='B'||s2[3]=='C'))||(s1[3]=='B'&&(s2[3]=='A'||s2[3]=='C'))||(s1[3]=='C'&&(s2[3]=='B'||s2[3]=='A'))||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D')){
			cout<<"1";
		}
	else cout<<"0";
	if((s1[3]=='F'&&s2[3]=='D')||(s1[3]=='D'&&s2[3]=='F')){
		cout<<"1";
	}
	if(s1[3]==s2[3]+1||s2[3]==s1[3]+1){ 
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
