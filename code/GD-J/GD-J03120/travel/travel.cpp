#include <bits/stdc++.h>
using namespace std;
void T()
{ cout<<"1"; }
void F()
{ cout<<"0"; }
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	long long s1n=(s1[0]+'0')*10+(s1[1]+'0'),s2n=(s2[0]+'0')*10+(s2[1]+'0'); 
	char s1m=s1[2],s2m=s2[2];  
	if(c1==c2) T();
	else{ cout<<"0000";return 0; }
	if(s1n==s2n) T();
	else{ cout<<"000";return 0; }
	if((s1m-'0')>=17&&(s1m-'0')<=19&&(s2m-'0')>=17&&(s2m-'0')<=19&&s1m!=s2m) T();
	else if((s1m-'0')>=20&&(s1m-'0')<=21&&(s2m-'0')>=20&&(s2m-'0')<=21&&s1m!=s2m)
	{ T(); }
	else{ F(); }
	if(abs(s1m-s2m)==1&&(s1m-'0')!=20&&(s1m-'0')!=21&&(s2m-'0')!=20&&(s2m-'0')!=21) T();
	else{ F(); }
	return 0;
}

