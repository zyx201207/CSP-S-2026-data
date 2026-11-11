#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='D'||b[2]=='F') n=1;
	else n=0;
	if(d[2]=='D'||b[2]=='F') m=1;
	else m=0;
	if(n==m) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	n=b[2]-'0'-64,m=d[2]-'0'-64;
	if(n-m==1||m-n==1) cout<<"1";
	else cout<<"1";
	return 0;
}

