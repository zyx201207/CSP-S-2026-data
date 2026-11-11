#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	char k1=s1[2];
	char k2=s2[2];
	int l1=0,l2=0;
	if(s1[0]=='1') l1+=10;
	if(s2[0]=='1') l2+=10;
	l1+=(s1[1]-'0');
	l2+=(s2[1]-'0');
	if(l1==l2) cout<<1;
	else cout<<0;
	
	bool lol=0;
	
	if((l1==l2)&&((k1=='D'&&k2=='F')||(k1=='F'&&k2=='D')||(k1=='A'&&k2=='C')||(k1=='A'&&k2=='B')||(k1=='B'&&k2=='C')||(k2=='A'&&k1=='C')||(k2=='A'&&k1=='B')||(k2=='B'&&k1=='C'))) lol=1;
	if(lol) cout<<1;
	else cout<<0;
	if(lol&&(!(k1=='A'&&k2=='C'))&&(!(k2=='A'&&k1=='C'))) cout<<1;
	else cout<<0;
	return 0;
}
