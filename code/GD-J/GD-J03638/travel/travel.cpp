#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d,ans="0000";
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(b[2]=='F') b[2]='E';
	if(d[2]=='F') d[2]='E';
	if(a==c){
		ans[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
			if((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C')){
				ans[2]='1';
				if(abs(b[2]-d[2])==1) ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
//8:43  100
