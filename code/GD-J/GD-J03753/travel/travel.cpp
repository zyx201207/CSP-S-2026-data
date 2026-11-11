#include <bits/stdc++.h>
#include <string>
using namespace std;
constexpr int N = 2e5+5;
struct ticket{
	string x;
	string s;
};
void solve(){
	ticket a,b;
	cin>>a.x>>a.s>>b.x>>b.s;
	bool flag1,flag2,flag3,flag4;
	flag1 = flag2 = flag3 = flag4 = false;
	if(a.x==b.x) flag1 = true;
	if(b.s[0]+b.s[1]==a.s[0]+a.s[1]) flag2 = true;
	if(b.s[0]+b.s[1]==a.s[0]+a.s[1]&&abs(a.s[2]-b.s[2])<=2&&!((a.s[2]=='C'&&b.s[2]=='D')||(a.s[2]=='D'&&b.s[2]=='C'))) flag3 = true;
	if(abs(a.s[2]-b.s[2])==1&&!((a.s[2]=='C'&&b.s[2]=='D')||(a.s[2]=='D'&&b.s[2]=='C'))) flag4 = true;
	if(flag1) cout<<1;
	else{
		cout<<"0000"<<endl;
		return;
	}if(flag2) cout<<1;
	else{
		cout<<"000"<<endl;
		return;
	}if(flag3) cout<<1;
	else{
		cout<<"00"<<endl;
		return;
	}if(flag4) cout<<1;
	else cout<<"0";
	cout<<endl;
	return;
}

int main(){
	freopen("travel3.in","r",stdin);
	freopen("travel3.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
