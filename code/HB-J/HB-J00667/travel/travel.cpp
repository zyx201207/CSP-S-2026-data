#include <bits/stdc++.h>
using namespace std;
#define int long long
string c,s,x,y;
int q=0,w=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>x>>y;
	if(c==x){
		cout<<1;
		if(s[0]==y[0]&&s[1]==y[1]){
			cout<<1;
			if(s[2]=='D'||s[2]=='F') q=1;
			else q=0;
			if(y[2]=='D'||y[2]=='F') w=1;
			else w=0;
			if(q==w){
				cout<<1;
				if(abs(s[2]-y[2])==1) cout<<1;
				else cout<<0;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
