#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
string c1,c2,s1,s2,ans="0000";
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans[0]='1';
	if(s1[0]==s2[0] && s1[1]==s2[1] && ans[0]=='1')ans[1]='1';
	if((((s1[2]=='A' || s1[2]=='B' ||s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' ||s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' ||s2[2]=='F')))&& ans[1]=='1')ans[2]='1';
	ll num=s1[2]-s2[2];
	if((abs(num)==1 && ans[2]=='1')&& ans[2]=='1')ans[3]='1';
	cout<<ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
