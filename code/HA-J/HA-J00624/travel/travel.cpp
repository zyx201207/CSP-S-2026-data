#include <bits/stdc++.h>
using namespace std;
string ss,cc,s,c; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ss>>cc>>s>>c;
	bool g1=0,g2=0;
	if(ss==s){cout<<1;g1=1;}
	else cout<<0;
	int d=0,e=0;
	d=d*10+(cc[0]-'0');
	d=d*10+(cc[1]-'0');
	e=e*10+(c[0]-'0');
	e=e*10+(c[1]-'0');
	if(d==e&&g1){cout<<1;g2=1;}
	else cout<<0;
	char aa=cc[2],a=c[2];
	bool f=0;
	if(aa>'C'&&a>'C') f=1;
	if(aa<='C'&&a<='C') f=1;
	if(f&&g1&&g2) cout<<1;
	else{cout<<0;f=0;}
	if(abs(a-aa)==1&&g1&&g2&&f) cout<<1;
	else if(a=='D'&&aa=='F') cout<<1;
	else if(aa=='D'&&a=='F') cout<<1;
	else cout<<0;
	return 0;
}
