//GZ-J00610贵阳市第十八中学王梓钰
#include<bits/stdc++.h>
using namespace std;
string m,n,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>s1>>n>>s2;
	if(m[0]-'0'==n[0]-'0'&&m[1]-'0'==n[1]-'0') cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0') cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F') cout<<"11";
		else cout<<"00";
	}
	if(s1[2]=='F'){
		if(s2[2]=='D') cout<<"11";
		else cout<<"00";
	}
	if(s1[2]=='A'){
		if(s2[2]=='B') cout<<"11";
		else if(s2[2]=='C') cout<<"10";
		else cout<<"00";
	}
	if(s1[2]=='B'){
		if(s2[2]=='A') cout<<"10";
		else if(s2[2]=='C') cout<<"11";
		else cout<<"00";
	}
	if(s1[2]=='C'){
		if(s2[2]=='B') cout<<"11";
		else if(s2[2]=='A') cout<<"10";
		else cout<<"00";
	}
	fclose(travel.in);
	fclose(travel.out);
	return 0;
}
