#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) {
		if(b[0]==d[0] && b[1]==d[1]) {
			char ch1=b[2],ch2=d[2];
			if((ch1<='C' && ch2<='C') || (ch1>='D' && ch2>='D')) {
				if(ch1-ch2==1 || ch2-ch1==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0 ;
}
