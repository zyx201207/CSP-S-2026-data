#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int cx1,zw1,cx2,zw2;
	cx1=(c1[0]-'0')*10+(c1[1]-'0');
	cx2=(c2[0]-'0')*10+(c2[1]-'0');
	if(cx1==cx2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	zw1=(s1[0]-'0')*10+(s1[1]-'0');
	zw2=(s2[0]-'0')*10+(s2[1]-'0');
	if(zw1==zw2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D'&&s2[2]=='D'||s2[2]=='D'&&s1[2]=='D')cout<<"11";
	else if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B')cout<<"11";
	else if(s1[2]=='C'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B')cout<<"11";
	else if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C')cout<<"10";
	else cout<<"00";
	return 0;
} 
