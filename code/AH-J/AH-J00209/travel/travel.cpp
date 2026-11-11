#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string s="0000";
string travel(string a,string b,string c,string d){
	string s="0000";
	if(a!=c)return s;
	if(a==c)s[0]='1';
	for(int i=1;i<=2;i++)if(b[i]==d[i])s[1]='1';
	if(s[1]=='0')return s;
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')s[2]='1';
	if(b[2]=='D'&&d[2]=='F'){s[2]='1';s[3]='1';}
	if(b[2]=='F'&&d[2]=='D'){s[2]='1';s[3]='1';}
	if(s[2]=='0')return s;
	if(b[2]-d[2]==1||d[2]-b[2]==1)s[3]='1';
	return s;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	cout<<travel(a,b,c,d);
	return 0;
}
