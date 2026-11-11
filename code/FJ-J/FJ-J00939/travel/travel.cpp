#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int a1,a2,b1,b2;
	a1=s1[0]-'0';
	a2=s1[1]-'0';
	b1=s2[0]-'0';
	b2=s2[1]-'0';
	int a=a1*10+a2;
	int b=b1*10+b2;
	if(a==b) cout<<1;
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	char a3=s1[2];
	char b3=s2[2];
	if(a3=='A'&&b3=='B' || a3=='B'&&b3=='C' || a3=='A'&&b3=='C' || a3=='B'&&b3=='A' || a3=='C'&&b3=='B' ||a3=='C'&&b3=='A' || a3=='D'&&b3=='F' || a3=='F'&&b3=='D' ) cout<<1;
	else {
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a3+1==b3||a3-1==b3) cout<<1;
	else cout<<0;
	return 0;
}
