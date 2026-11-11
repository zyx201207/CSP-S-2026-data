#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;

bool sameside(char a,char b)
{
	if((a=='D' && b=='F') || (a=='F' && b=='D')) return true;
	else if(a=='D' || a=='F' || b=='D' || b=='F') return false;
	return true;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else if(s1[0]!=s2[0] || s1[1]!=s2[1]) cout<<"1000";
	else if(!(sameside(s1[2],s2[2]))) cout<<"1100";
	else if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')) cout<<"1110";
	else cout<<"1111";
	return 0;
}

