#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[3],s2[3];
	int c1,c2;
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
	}else if(c1!=c2){
		cout<<"0";
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2){
		cout<<"1";
	}else {
		cout<<"0";
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2&&s1[3]=='d'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D'&&s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2||s1[3]=='A'&&s2[3]=='B'&&s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2||s1[3]=='B'&&s2[3]=='A'&&s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2||s1[3]=='B'&&s2[3]=='C'&&s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2||s1[3]=='C'&&s2[3]=='B'&&s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2){
		cout<<"11";
	}else if(s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2&&s1[3]=='A'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='A'&&s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2){
		cout<<"10";
	}else{
		cout<<"00";
	}
	return 0;
}
