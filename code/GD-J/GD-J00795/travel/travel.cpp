#include<bits/stdc++.h>
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e5+10;
void _freopen(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
bool cheak(char a,char b){
	bool p1=0,p2=0;
	if(a>='A'&&a<='C') p1=1;
	if(b>='A'&&b<='C') p2=1;
	if(p1==p2) return 1;
	return 0;
}
void solve(){
	string a,b,s,t;
	cin>>a>>b>>s>>t;
	string ans="";
	if(a==s) ans=ans+"1";
	else ans=ans+"0";
	if(ans[0]=='1'&&b[0]==t[0]&&b[1]==t[1]) ans=ans+"1";
	else ans=ans+"0";
	if(ans[1]=='1'&&cheak(b[2],t[2])){
		ans=ans+"1";
	}else ans=ans+"0";
	if(ans[2]=='1'&&abs(b[2]-t[2])==1) ans=ans+"1";
	else ans=ans+"0";
	cout<<ans;
	
}
signed main(){
	No TLE
	_freopen();
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

