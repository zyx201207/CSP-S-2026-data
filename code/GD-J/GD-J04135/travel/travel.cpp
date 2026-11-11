#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool p=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int sd=0,sf=0;
	for(int i=0;i<=1;i++){
		sd=sd*10+c1[i]-'0';
		sf=sf*10+c2[i]-'0';
	}
	if(sd==sf)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	sd=0;
	sf=0;
	for(int i=0;i<=1;i++){
		sd=sd*10+s1[i]-'0';
		sf=sf*10+s2[i]-'0';
	}
	if(sd==sf)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='c')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))cout<<1;
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	int k,l;
	k=s1[2]-'A'+1;
	l=s2[2]-'A'+1;
	if(abs(k-l)==1)cout<<1;
	else {
		cout<<0;
		return 0;
	}
	return 0;
}
