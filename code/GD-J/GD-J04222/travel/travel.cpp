#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
string s1,s2,s3,s4;
void input(){
	cin>>s1>>s2>>s3>>s4;
}
void solve(){
	input();
	if(s1[0]!=s3[0]||s1[1]!=s3[1]) cout<<"0000";
	elif(s2[0]!=s4[0]||s2[1]!=s4[1]) cout<<"1000";
	elif((s2[2]>'C'||s4[2]>'C')&&(s2[2]<'D'||s4[2]<'D')) cout<<"1100";
	elif((s2[2]=='A'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='A')) cout<<"1110";
	else cout<<"1111";
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}//Trick||Treat!
