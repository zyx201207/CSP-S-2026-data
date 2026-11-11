#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+9;
string c1,s1,c2,s2;
int x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	x=(s1[0]-'0')*10+(s1[1]-'0');
	y=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2&&x==y) cout<<1;
	else cout<<0;
	if(c1==c2&&x==y&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<1;
	else cout<<0;
	if(c1==c2&&x==y&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<1;
	else cout<<0;	
	return 0;
}
