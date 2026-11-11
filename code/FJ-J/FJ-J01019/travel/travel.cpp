#include<bits/stdc++.h>
using namespace std;
#define int long long
int a1,a2,mp[128];
string s1,s2;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['E']=2;
	if(mp[s1[2]]==mp[s2[2]]) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
