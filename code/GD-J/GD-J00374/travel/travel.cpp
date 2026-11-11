#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)cout<<1;
	else cout<<0;
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1])cout<<1;
	else cout<<0;
	char a=c2[2],b=c4[2];
	if(a<b)swap(a,b);
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&((a=='F'&&b=='D')||(a=='C'&&b=='B')||(a=='C'&&b=='A')||(a=='B'&&b=='A')))cout<<1;
	else cout<<0;
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&((a=='F'&&b=='D')||(a=='C'&&b=='B')||(a=='B'&&b=='A')))cout<<1;
	else cout<<0;
	return 0;
} 
