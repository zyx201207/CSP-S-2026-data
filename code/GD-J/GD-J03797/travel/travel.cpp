#include <bits/stdc++.h>
using namespace std;
string a,c;
char g,h;
string s;
int b,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>b>>a>>d>>c;
	g = a[2];
	h = c[2];
	if(a[0]=='0')e = a[1]-'0';
	else e = (a[0]-'0')*10+a[1]-'0';
	if(c[0]=='0')f = c[1]-'0';
	else f = (c[0]-'0')*10+c[1]-'0';
	if(b==d)s+='1';
	else s+='0';
	if(b==d&&e==f)s+='1';
	else s+='0';
	if(b==d&&e==f&&g<='C'&&g>='A'&&h>='A'&&h<='C')s+='1';
	else if(b==d&&e==f&&g<='F'&&g>='D'&&h>='D'&&h<='F')s+='1';
	else s+='0';
	if(b==d&&max(g,h)-min(g,h)==1&&e==f&&g<='C'&&g>='A'&&h>='A'&&h<='C')s+='1';
	else if(e==f&&b==d&&max(g,h)-min(g,h)==2&&g<='F'&&g>='D'&&h>='D'&&h<='F')s+='1';
	else s+='0';
	
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
