#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int a,b;
	if(s1[2]=='A') a=1;
	if(s1[2]=='B') a=2;
	if(s1[2]=='C') a=3;
	if(s1[2]=='D') a=4;
	if(s1[2]=='E') a=5;
	if(s2[2]=='A') b=1;
	if(s2[2]=='B') b=2;
	if(s2[2]=='C') b=3;
	if(s2[2]=='D') b=4;
	if(s2[2]=='E') b=5;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if((a<=3 && b<=3) or (4<=a && 4<=b)){
				cout<<1;
				if(a+1==b or b+1==a) cout<<1;
				else cout<<0;return 0;
			} 
			else cout<<0<<0;return 0;
		} 
		else cout<<0<<0<<0;return 0;
	} 
	else cout<<0<<0<<0<<0;
	return 0; 
} 
