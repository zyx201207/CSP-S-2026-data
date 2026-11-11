#include<bits/stdc++.h>
using namespace std;
string s[2],c[2]; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	cout<<(c[0]==c[1]);
	cout<<(c[0]==c[1]&&s[0][0]==s[1][0]&&s[0][1]==s[1][1]);
	cout<<(c[0]==c[1]&&s[0][0]==s[1][0]&&s[0][1]==s[1][1]&&!(s[0][2]<='C' ^ s[1][2]<='C'));
	cout<<(c[0]==c[1]&&s[0][0]==s[1][0]&&s[0][1]==s[1][1]&&!(s[0][2]<='C' ^ s[1][2]<='C')&&min(s[1][2],s[0][2])==max(s[1][2],s[0][2])-1);
	return 0;
}
