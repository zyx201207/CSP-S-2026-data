#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;
const int mo1=1e9+7,mo2=1e9+9;
string x,y,s,t;
void solve(){
	cin>>x>>s>>y>>t;
	if(x[1]==y[1]) cout<<1;
	else{
		cout<<"0000";
		return ;
	}
	if(s[0]==t[0]&&s[1]==t[1]) cout<<1;
	else{
		cout<<"000";
		return ;
	}
	if( (s[2]<='C'&&t[2]<='C')||(s[2]>='D'&&t[2]>='D') ) cout<<1;
	else{
		cout<<"00";
		return ;
	}
	if( ( (s[2]<='C'&&t[2]<='C')||(s[2]>='D'&&t[2]>='D') )&&abs(s[2]-t[2])==1&&s[0]==t[0]&&s[1]==t[1]) cout<<1;
	else cout<<"0";
	return ;
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
