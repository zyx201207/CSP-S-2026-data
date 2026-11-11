#include<bits/stdc++.h>
using namespace std;
string r,x,sr,sx;
int getnum(char c)
{
	if(c=='D') return 'D'+1-'A';
	return c-'A';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>sr>>x>>sx;
	if(r!=x) cout<<"0000";
	else if(sr[0]!=sx[0]||sr[1]!=sx[1]) cout<<"1000";
	else if(!((sr[2]<='C'&&sx[2]<='C')||(sr[2]>'C'&&sx[2]>'C'))) cout<<"1100";
	else if(abs(getnum(sr[2])-getnum(sx[2]))!=1) cout<<"1110";
	else cout<<"1111";
	return 0;
}
