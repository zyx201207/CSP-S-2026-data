#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
string s,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s;
	cin>>b>>t;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int c,d;
	c=s[0]-'0';
	c*=10;
	c+=s[1]-'0';
	d=t[0]-'0';
	d*=10;
	d+=t[1]-'0';
	if(c==d){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s[2]=='D'&&t[2]=='F'||s[2]=='F'&&t[2]=='D'){
		cout<<11;
		return 0;
	}
	if(s[2]=='D'||t[2]=='F'||s[2]=='F'||t[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(s[2]=='A'&&t[2]=='C'||s[2]=='C'&&t[2]=='A'){
		cout<<10;
		return 0;
	}
	cout<<"11";
	return 0;
}
