#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],s1[5],s2[5];
signed main() {//Î¨Ò»Õý½â£¬O(1)
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"0000";
	else {
		bool f=(s1[0]==s2[0]&&s1[1]==s2[1]);
		cout<<1;
		if(f) cout<<1;
		else cout<<0;
		if(f&&(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))) cout<<1;
		else cout<<0;
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'||(s1[2]=='F'&&s2[2]=='D'))) cout<<1;
		else cout<<0;
	}
	return 0;
}
