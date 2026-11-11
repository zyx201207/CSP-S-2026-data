#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c_,s_;
	cin>>c>>s>>c_>>s_;
	if(c==c_) {
		cout<<"1";
		bool ok=true;
		for(int i=0; i<2; i++) {
			if(s[i]!=s_[i]) {
				cout<<"000";
				ok=false;
				break;
			}
		}
		if(ok) {
			cout<<"1";
			if(s[2]>='D'&&s_[2]>='D'||s[2]<'D'&&s_[2]<'D') {
				cout<<"1";
				if(s[2]<'D'&&s_[2]<'D'&&abs(s[2]-s_[2])==1) {
					cout<<"1";
				} else if(s[2]>='D'&&s_[2]>='D') {
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else {
				cout<<"00";
			}
		}
	} else {
		cout<<"0000";
	}

	return 0;
}
