#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[100];
inline void solve(){
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	if(s[0]!=s[2])cout<<"0000\n";
	else if(s[1][0]!=s[3][0]||s[1][1]!=s[3][1])cout<<"1000\n";
	else if((s[1][2]<='C'&&s[3][2]>='D')||(s[1][2]>='D'&&s[3][2]<='C'))cout<<"1100\n";
	else if(s[1][2]+1!=s[3][2]&&s[3][2]+1!=s[1][2])cout<<"1110\n";
	else cout<<"1111\n";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
