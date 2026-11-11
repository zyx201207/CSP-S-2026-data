#include<bits/stdc++.h>
using namespace std;
string s;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	getline(cin,s);
	if(s[0]==s[7]&&s[1]==s[8]) cout<<1;
	else cout<<0;
	if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11])cout<<1;
	else cout<<0;
	if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&!((s[5]=='C'&&s[12]=='D')||(s[5]=='D'&&s[12]=='C'))) cout<<1;
	else cout<<0;
	if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&!((s[5]=='C'&&s[12]=='D')||(s[5]=='D'&&s[12]=='C'))&&abs(int(s[5]-s[12]))==1) cout<<1;
	else cout<<0;
	return 0;
} 
