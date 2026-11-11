#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int e=(s1[0]-'0')*10+s1[1]-'0';
	int d=(s2[0]-'0')*10+s2[1]-'0';
	int a=s1[2]-'0';
	int b=s2[2]-'0';
	bool cx=0,p=0,c=0,l=0;
	if(c1[0]==c2[0]&&c1[1]==c2[1])cx=1;
	else {
		cout<<cx<<p<<c<<l;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		p=1;
		if(s1[2]>'C'&&s2[2]>'C')c=1;
		if(s1[2]<='C'&&s2[2]<='C')c=1;
	}
	if(a-1==b||a+1==b){
		if(s1[2]=='C'&&s2[2]=='D')
			l=0;
		else if(s2[2]=='C'&&s1[2]=='D')
			l=0;
		else l=1;
	}
	else if(a==b&&abs(e-d)==1)l++;
	else if(s1[2]=='D'&&s2[2]=='F')l++;
	else if(s2[2]=='D'&&s1[2]=='F')l++;
	cout<<cx<<p<<c<<l;
	return 0;
}
