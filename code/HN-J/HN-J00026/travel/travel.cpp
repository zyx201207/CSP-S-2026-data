#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=100005;
string a,b,c,d;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int ok=0;
	if(a==c) {
		cout<<1;
	} else {
		ok=1;
	}
	if(ok==1) {
		cout<<"0000";
		return 0;
	}
	char cnta[M],cntb[M],nowc,nowb;
	for(int i=0; i<b.size()-1; i++) {
		cnta[i]=b[i];
		cntb[i]=d[i];
	}
	int t=b.size()-1;
	nowc=b[t],nowb=d[t];
	string x=cnta,y=cntb;
	if(x==y) {
		cout<<1;
	} else ok=1;
	if(ok==1) {
		cout<<"000";
		return 0;
	}
	int xa=nowc-'0',xb=nowb-'0';
	if(abs(xa-xb)<=2) {
		if(nowc=='C'&&nowb=='D')ok=1;
		else cout<<1;
	}
	if(ok==1) {
		cout<<"00";
		return 0;
	} else if(abs(xa-xb)==1)cout<<1;
	else cout<<0;
	return 0;
}
