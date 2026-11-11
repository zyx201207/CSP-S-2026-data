#include<bits/stdc++.h>
using namespace std;

string s1,a1;
char s[3],a[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s[0]>>s[1]>>s[2]>>a1>>a[0]>>a[1]>>a[2];
	if(s1==a1) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if((a[0]!=s[0])||(a[1]!=s[1])){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(s[2]=='D'){
		if(a[2]=='F') cout<<"11";
		else cout<<"00";
	}
	else if(s[2]=='F'){
		if(a[2]=='D') cout<<"11";
		else cout<<"00";
	}
	else if(s[2]=='A'){
		if(a[2]=='B') cout<<"11";
		else if(a[2]=='C') cout<<"10";
		else cout<<"00";
	}
	else if(s[2]=='C'){
		if(a[2]=='B') cout<<"11";
		else if(a[2]=='A') cout<<"10";
		else cout<<"00";
	}
	else if(s[2]=='B'){
		if(a[2]=='A') cout<<"11";
		else if(a[2]=='C') cout<<"11";
		else cout<<"00";
	}
	return 0;
}
