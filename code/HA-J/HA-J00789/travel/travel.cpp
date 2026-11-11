#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s1=0,s2=0;
int main(){
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a==c)cout<<1;
	else cout<<0;
	if(b[2]=='D'||b[2]=='F')s1=1;
	if(d[2]=='D'||d[2]=='F')s2=1;
	if(s1==s2&&b[0]==d[0]&&b[1]==d[1]&&a==c)cout<<1;
	else cout<<0;
	if(s1==s2&&b[0]==d[0]&&b[1]==d[1]&&a==c&&(b[2]==(d[2]+1)||(b[2]+1)==d[2]))cout<<1;
	else cout<<0;
	return 0;
}
