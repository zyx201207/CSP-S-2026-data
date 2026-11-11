#include<bits/stdc++.h>
#define int long long
using namespace std;
string sc,ss,ec,es;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>sc>>ss>>ec>>es;
	if(sc!=ec)
		cout<<"0000";
	else
		if(ss[0]!=es[0]||ss[1]!=es[1])
			cout<<"1000";
		else
			if(ss[2]<'D'&&es[2]>'C'||ss[2]>'C'&&es[2]<'D')
				cout<<"1100";
			else
				if(ss[2]=='A'&&es[2]=='C'||ss[2]=='C'&&es[2]=='A')
					cout<<"1110";
				else
					cout<<"1111";
	return 0;
}
