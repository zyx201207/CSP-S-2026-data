#include<bits/stdc++.h>
using namespace std;
bool pd(char a,char b){//ÅÐ¶Ï¹ýµÀ²à 
	if(a>='A'&&a<='C') {
		if(b>='A'&&b<='C') return 1;
		else return 0;
	}
	if(a>='D'&&a<='F'){
		if(a>='D'&&a<='F') return 1;
		else return 0;
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;//a³µÏáºÅx     b×ùÎ»ºÅx    c³µÏáºÅy   d×ùÎ»ºÅy
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(pd(b[2],d[2])) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((b[2]=='D'&&d[2]=='E')||(d[2]=='D'&&b[2]=='E')||d[2]-1==b[2]||d[2]+1==b[2]) cout<<1;
	else cout<<0;
	return 0;	
}
