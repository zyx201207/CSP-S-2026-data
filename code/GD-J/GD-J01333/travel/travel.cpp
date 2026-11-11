#include<bits/stdc++.h>
#define int long long
#define per(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,y,x) for(int i=y;i>=x;i--)
using namespace std;
string c1,s1,c2,s2;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01" || c1=="16" || c2=="01" || c2=="16") {cout<<"0000";return 0;}
	cout<<(c1==c2);
	cout<<(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]);
	cout<<(c1==c2 && (s1[0]==s2[0] && s1[1]==s2[1]) && (((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F'))));
	cout<<(c1==c2 && ((s1[0]==s2[0] && s1[1]==s2[1]) && (((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) || ((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F')))) && ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')));
	return 0;
}
