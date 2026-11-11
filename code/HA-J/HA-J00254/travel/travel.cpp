#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=1,f2=0,f1=0,f4=0,f5=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		f2=1;
		cout<<1;
	}
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f2) {
		f1=1;
		cout<<1;
	}
	else cout<<0;
	if(f1&&((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))) cout<<1;
	else {
		cout<<0;
		f1=0;	
	}
	if(!(s1[2]=='A'&&s2[2]=='C')&&!(s2[2]=='A'&&s1[2]=='C')&&f1) cout<<1;
	else {
		cout<<0;
	}
	return 0;
}
