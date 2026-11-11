#include<bits/stdc++.h>
using namespace std;
long long c1,c2,x,y;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=(s1[0]-'0')*10+s1[1]-'0';
	y=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(x==y) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]=='D' && s2[2]=='F') cout<<1;
	else if(s1[2]=='F' && s2[2]=='D') cout<<1;
	else if(s1[2]=='A' && s2[2]=='B') cout<<1;
	else if(s1[2]=='A' && s2[2]=='C') cout<<1;
	else if(s1[2]=='B' && s2[2]=='C') cout<<1;
	else if(s1[2]=='B' && s2[2]=='A') cout<<1;
	else if(s1[2]=='C' && s2[2]=='A') cout<<1;
	else if(s1[2]=='C' && s2[2]=='B') cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(s1[2]-1==s2[2] || s1[2]+1==s2[2]) cout<<1;
	else cout<<0;
	return 0;
}
