#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2,d1,d2;
char a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>d1>>a>>c2>>d2>>b;
	if(c1==c2)cout<<1; else{cout<<"0000";return 0;}
	if(d1==d2)cout<<1; else{cout<<"000";return 0;}
	if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F')))cout<<1; else{cout<<"00";return 0;}
	if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))cout<<1; else cout<<0;
	return 0;
}
