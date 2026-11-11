#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<1;
			if((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C')){
				cout<<1;
				if(abs(b[2]-d[2])==1) cout<<1;
				else cout<<0;
			}
			else if((b[2]>='D' && b[2]<='E' && d[2]>='D' && d[2]<='E'))
				cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

