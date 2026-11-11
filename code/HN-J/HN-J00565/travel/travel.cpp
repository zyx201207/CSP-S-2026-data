#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1;
	cin>>a1;
	string a2;
	cin>>a2;
	string b1;
	cin>>b1;
	string b2;
	cin>>b2;
	if(a1==b1) cout<<1;
	else cout<<0;
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]) cout<<1;
	else cout<<0;
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]) cout<<1;
	else cout<<0;
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&(((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))||((a2[2]=='D'||a2[2]=='E')&&(b2[2]=='D'||b2[2]=='E'||b2[2]=='C')))) cout<<1;
	else cout<<0;
	return 0;
}
