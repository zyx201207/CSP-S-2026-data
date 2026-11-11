#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2) {
		cout<<"1";
		if(s1[0]==s3[0]&&s1[1]==s3[1]){
			cout<<"1";
			if(s1[2]=='A' && s3[2]=='B') cout<<"11";
			else if(s1[2]=='A' && s3[2]=='C') cout<<"10";
			else if(s1[2]=='A' && (s3[2]=='D' || s3[3]=='E')) cout<<"00";
			else if(s1[2]=='B' && (s3[2]=='A' || s3[3]=='C')) cout<<"11";
			else if(s1[2]=='B' && (s3[2]=='D' || s3[3]=='E')) cout<<"00";
			else if(s1[2]=='C' && s3[2]=='B') cout<<"11";
			else if(s1[2]=='C' && s3[2]=='A') cout<<"10";
			else if(s1[2]=='C' && (s3[2]=='D' || s3[3]=='E')) cout<<"00";
			else if(s1[2]=='D' && s3[2]=='E') cout<<"11";
			else if(s1[2]=='D' && (s3[2]=='A' || s3[3]=='B' || s[3]=='C')) cout<<"00";
			else if(s1[2]=='E' && s3[2]=='D') cout<<"11";
			else if(s1[2]=='E' && (s3[2]=='A' || s3[3]=='B' || s[3]=='C')) cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

