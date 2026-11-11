#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
string a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc) a+='1';
	else a+='0';
	string b,c;
	b=s[0]+s[1];
	c=ss[0]+ss[1];
	if(b==c&&a[0]=='1') a+='1';
	else a+='0';
	if((s[2]<='C'&&ss[2]<='C'||s[2]>='D'&&ss[2]>='D')&&a[1]=='1') a+='1';
	else a+='0';
	if(abs(int(s[2]-ss[2]))==1&&a[2]=='1') a+='1';
	else a+='0';
	cout<<a; 
	return 0;
}
