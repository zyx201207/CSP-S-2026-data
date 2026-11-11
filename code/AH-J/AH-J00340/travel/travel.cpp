#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool f1=(s1==s3);
	bool f2=f1&&(s2[1]==s4[1]&&s2[0]==s4[0]);
	bool f3=f2&&(s2[2]=='A'&&s4[2]=='B' || 
		         s2[2]=='A'&&s4[2]=='C' || 
		         s2[2]=='B'&&s4[2]=='A' || 
		         s2[2]=='B'&&s4[2]=='C' || 
		         s2[2]=='C'&&s4[2]=='A' || 
		         s2[2]=='C'&&s4[2]=='B' ||
		         s2[2]=='D'&&s4[2]=='F' || 
		         s2[2]=='F'&&s4[2]=='D' );
	bool f4=f3&&(abs(s2[2]-s4[2])==1);
	cout<<f1<<f2<<f3<<f4;
	return 0;
}