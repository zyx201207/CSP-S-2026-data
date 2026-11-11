#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int z,x,c,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>d>>f;
	if(a==d)
		z=1;
	if(s[0]==f[0]&&s[1]==f[1]&&z==1)
		x=1;
	if(((s[2]<='C'&&f[2]<='C')||((s[2]=='D'||s[2]=='f')&&(f[2]=='D'||f[2]=='f')))&&x==1)
		c=1;
	if(c==1){
		s[2]-='0';
		f[2]-='0';
		if(s[2]-f[2]==1||f[2]-s[2]==1)
			v=1;
	}
	cout<<z<<x<<c<<v;
	return 0;
}
