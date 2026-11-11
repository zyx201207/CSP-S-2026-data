#include<bits/stdc++.h>
#define int long long
using namespace std;
string as,bs,a,b;
bool check(char x,char y){
	if(x<='C'&&y<='C'||x>'C'&&y>'C')return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>as>>b>>bs;
	if(a==b)cout<<1;
	else cout<<0;
	if(a==b&&as.substr(0,2)==bs.substr(0,2))cout<<1;
	else cout<<0;
	char x=as[as.size()-1],y=bs[bs.size()-1];
	if(a==b&&as.substr(0,2)==bs.substr(0,2)&&check(x,y))cout<<1;
	else cout<<0;
	if(a==b&&as.substr(0,2)==bs.substr(0,2)&&check(x,y)&&abs(x-y)==1)cout<<1;
	else cout<<0;
	return 0;
}
