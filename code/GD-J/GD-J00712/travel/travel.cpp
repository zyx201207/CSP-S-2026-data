#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)cout<<'1';
	else cout<<'0';
	string a="",b="";
	a+=c1[0]+c1[1];
	b+=c2[0]+c2[1];
	if(s1==s2 and a==b)cout<<'1';
	else cout<<'0';
	if(s1==s2 and a==b and ((c1[2]=='A' and c2[2]=='B') or (c1[2]=='B' and c2[2]=='A') or (c1[2]=='A' and c2[2]=='C') or (c1[2]=='C' and c2[2]=='A') or (c1[2]=='C' and c2[2]=='B') or (c1[2]=='B' and c2[2]=='C') or (c1[2]=='E' and c2[2]=='F') or (c1[2]=='F' and c2[2]=='E')))cout<<'1';
	else cout<<'0';
	if(s1==s2 and a==b and ((c1[2]=='A' and c2[2]=='B') or (c1[2]=='B' and c2[2]=='A') or (c1[2]=='C' and c2[2]=='B') or (c1[2]=='B' and c2[2]=='C') or (c1[2]=='E' and c2[2]=='F') or (c1[2]=='F' and c2[2]=='E')))cout<<'1';
	else cout<<'0';
	return 0;
}
