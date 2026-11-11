#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int a=s1[2],b=s2[2];
	if((a>=65&&a<=67&&b>=65&&b<=67)||(a>=68&&a<=70&&b>=68&&b<=70)) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))
		cout<<'1';
	else cout<<0;
	//65
	//70
	return 0;
}
