#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
string c1,c2,s1,s2;
int main() {
	wc("travel");
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			cout<<1;
			if((s1[2]>'C'&&s2[2]>'C') or (s1[2]<='C'&&s2[2]<='C') ) {
				cout<<1;
				if((abs((int)(s1[2])-(int)(s2[2]))==1) or (s1[2]=='D'&&s2[2]=='F') or (s2[2]=='D'&&s1[2]=='F')) cout<<1;
				else cout<<0;
			} else cout<<"00";
		} else cout<<"000";
	} else cout<<"0000";
	cout<<'\n';	
	return 0;
}
