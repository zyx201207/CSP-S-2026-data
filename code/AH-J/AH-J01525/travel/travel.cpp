#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2) cout<<"0000";
	else if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"1000";
	else if(c1[2]=='A'&&c2[2]=='B'||c1[2]=='B'&&c2[2]=='A'||c1[2]=='C'&&c2[2]=='B'||c1[2]=='B'&&c2[2]=='C'||c1[2]=='D'&&c2[2]=='E'||c1[2]=='E'&&c2[2]=='D') cout<<"1111";
	else if(c1[2]=='A'&&c2[2]=='C'||c1[2]=='C'&&c2[2]=='A') cout<<"1110";
	else cout<<"1100";
	return 0;
} 
