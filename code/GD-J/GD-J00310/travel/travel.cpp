#include<bits/stdc++.h>
#define int long long
using namespace std;
int LADDM,ans[5];
string cr,sr,cx,sx;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx) ans[1]=1;
	if(cr==cx&&sr[0]==sx[0]&&sr[1]==sx[1]) ans[2]=1;
	if(cr==cx&&sr[0]==sx[0]&&sr[1]==sx[1]&&((sr[2]=='D'&&sx[2]=='E')||(sr[2]=='E'&&sx[2]=='D')||(sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='A'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='A')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B'))) ans[3]=1;
	if(cr==cx&&sr[0]==sx[0]&&sr[1]==sx[1]&&((sr[2]=='D'&&sx[2]=='E')||(sr[2]=='E'&&sx[2]=='D')||(sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B'))) ans[4]=1;
	for(int i=1;i<=4;i++) cout<<ans[i];
}
