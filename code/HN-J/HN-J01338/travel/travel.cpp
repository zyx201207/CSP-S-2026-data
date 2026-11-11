#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool q[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1[0]+s1[1]==s2[0]+s2[1]) cout<<1;
	else cout<<0;
	bool c=((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'));
	bool d=((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'));
	if((s1[0]+s1[1]==s2[0]+s2[1])&&(c||d)) cout<<1;
	else cout<<0;
	if(c1==c2&&(c||d)&&(s1[2]+1==s2[2]||s2[2]+1==s1[2])) cout<<1;
	else cout<<0;
	return 0;
}
