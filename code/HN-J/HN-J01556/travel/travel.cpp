#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	string s1,s2;
	char a,b;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	a=s1[2];
	b=s2[2];
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C')cout<<1;
		else cout<<0;
	}
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F')cout<<1;
		else cout<<0;
	}	
	if(a+1==int(b)||a-1==int(b)){
		if(a=='D'&&b=='C')cout<<0;
		else if(b=='D'&&a=='C')cout<<0;
		else cout<<1;
	}
	return 0;
} 
