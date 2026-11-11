#include<bits/stdc++.h>
using namespace std;
char c1[2],c2[2];
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3]>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	if(c1[1]==c2[1]&&c1[2]==c2[2]) {
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<"1";
		if(s1[3]=='A'&&s2[3]=='B') cout<<"1";
		else if(s1[3]=='A'&&s2[3]=='C') cout<<"1";
		else if(s1[3]=='B'&&s2[3]=='C') cout<<"1";
		else if(s1[3]=='B'&&s2[3]=='A') cout<<"1";
		else if(s1[3]=='C'&&s2[3]=='A') cout<<"1";
		else if(s1[3]=='C'&&s2[3]=='B') cout<<"1";
		else if(s1[3]=='D'&&s2[3]=='F') cout<<"1";
		else if(s1[3]=='F'&&s2[3]=='D') cout<<"1";
		else cout<<"0";
		if(s1[3]=='A'&&s2[3]=='B') cout<<"1";
		else if(s1[3]=='B'&&s2[3]=='C') cout<<"1";
		else if(s1[3]=='D'&&s2[3]=='F') cout<<"1";
		else if(s1[3]=='B'&&s2[3]=='A') cout<<"1";
		else if(s1[3]=='C'&&s2[3]=='B') cout<<"1";
		else if(s1[3]=='F'&&s2[3]=='D') cout<<"1";
		else cout<<"0";
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	return 0;
}
