#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int z,zz;
	string w,ww;
	cin>>z>>w>>zz>>ww;
	if(z==zz) {
		cout<<1;
	} else {
		cout<<"0000";
		return 0;
	}
	if(w[0]==ww[0]&&w[1]==ww[1]) {
		cout<<1;
	} else {
		cout<<"000";
		return 0;
	}
	if((w[2]=='D'&&ww[2]=='F')||(w[2]=='F'&&ww[2]=='D')) {
		cout<<11;
		return 0;
	} else if(w[2]=='D'||ww[2]=='D'||ww[2]=='F'||w[2]=='F') {
		cout<<"00";
		return 0;
	} else {
		cout<<1;
	}if(w[2]==ww[2]+1||w[2]==ww[2]-1)
	{
		cout<<1;
	}else
	{
		cout<<0;
	}
	return 0;
}
