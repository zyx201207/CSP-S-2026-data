#include <bits/stdc++.h>
using namespace std;
	
int main() {
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char c1=s1[1],c2=s3[1];
	bool a=(c1-'0'==c2-'0');
	cout<<a;
	c1=s2[0],c2=s2[1];
	int a1=(c1-'0')*10+c2-'0';
	c1=s4[0],c2=s4[1];
	int a2=(c1-'0')*10+c2-'0';
	int b=a&&(a1==a2);
	cout<<b;
	bool c=b&&(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F')));
	cout<<c;
	c1=s2[2],c2=s4[2];
	bool d=c&&(c1-c2==1||c2-c1==1);
	cout<<d;
}
