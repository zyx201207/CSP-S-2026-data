#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s,c;
	string s1,s2,c1,c2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<1;
	else cout<<0;
	if(c2[0]==s2[0]&&c2[1]==s2[1]&&s2[2]!=c2[2])cout<<1;
	else cout<<0;
	c=c2[2];
	s=s2[2];
	if(s2[0]==c2[0]&&s2[1]==c2[1]&&((c=='A'&&s=='B')||(c=='A'&&s=='C')||(c=='B'&&s=='C')||(c=='B'&&s=='A')||(c=='C'&&s=='B')||(c=='C'&&s=='A')||(c=='D'&&s=='F')||(c=='F'&&s=='D')))
		cout<<1;
	else cout<<0;
	if(s2[0]==c2[0]&&s2[1]==c2[1]&&((c=='A'&&s=='B')||(c=='B'&&s=='C')||(c=='B'&&s=='A')||(c=='C'&&s=='B')||(c=='D'&&s=='F')||(c=='E'&&s=='F')))
		cout<<1;
	else cout<<0;

	return 0;
}

