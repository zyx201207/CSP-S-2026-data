#include <bits/stdc++.h> 
using namespace std;
int main() {
	freopen("traval.in","r",stdin);
	freopen("traval.out","W",stdout);
	char a[2],s[3],d[2],f[3];
	cin>>a>>s>>d>>f;
	if(a[0]==d[0]&&a[1]==d[1]) cout<<1;
	else {
	cout<<0<<0<<0<<0;
	return 0;
}
	if(s[0]==f[0]&&s[1]==f[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(f[2]=='F'&&s[2]=='D'||s[2]=='F'&&f[2]=='D')
	{
		cout<<1<<1;
		return 0;
	}
	if(s[2]=='A'&&f[2]=='C'||f[2]=='A'&&s[2]=='C')
	{
		cout<<1<<0;
		return 0;
	}
	if(s[2]=='B'&&f[2]=='C'||s[2]=='B'&&f[2]=='A'||s[2]=='A'&&f[2]=='B'||s[2]=='C'&&f[2]=='B')
	{
		cout<<1<<1;
	}
	else cout<<0<<0;
	return 0;
}
