#include<bits/stdc++.h>
using namespace std;
//const int N=
string c,s,cc,ss;
int r,x;
int main(){
	//¹Ø×¢luogu 1406766 Ð»Ð»ß÷
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(s[2]=='D') s[2]='E';
	if(ss[2]=='D')ss[2]='E';
	if(s[2]<='C')r=1;
	if(ss[2]<='C') x=1;
	
	if(c==cc)cout<<1;
	else cout<<0;
	
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]) cout<<1;
	else cout<<0;
	
	
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&r==x) cout<<1;
	else cout<<0;
	
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&(s[2]==ss[2]+1||ss[2]==s[2]+1)) cout<<1;
	else cout<<0;
	return 0;
}

