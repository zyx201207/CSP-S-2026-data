#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(int(s1[1])+int(s1[0])*10==int(s2[1])+int(s2[0])*10) cout<<1;
	else cout<<0;
	if((s1[2]=='D' && s2[2]=='E') || (s2[2]=='D' && s1[2]=='E') || (s1[2]!='D' && s2[2]!='E') || (s1[2]!='E' && s2[2]!='D')) cout<<1;
	else cout<<0;
	if((s1[2]=='D' && s2[2]=='E') || (s2[2]=='D' && s1[2]=='E')) cout<<1;
	else if(s1[2]=='B' || s2[2]=='B') cout<<1;
	else cout<<0;
	return 0;
}
