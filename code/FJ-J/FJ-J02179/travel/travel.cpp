#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int lr[256],seat[256];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	lr['A']=lr['B']=lr['C']=1;
	lr['D']=lr['F']=0;
	seat['A']=1,seat['B']=2,seat['C']=3,seat['D']=4,seat['F']=5;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1]))cout<<1;
	else cout<<0;
	if((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&(lr[(int)s1[2]]==lr[(int)s2[2]]))cout<<1;
	else cout<<0;
	if((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&(lr[(int)s1[2]]==lr[(int)s2[2]])&&abs(seat[(int)s1[2]]-seat[(int)s2[2]])==1)cout<<1;
	else cout<<0;
	cout<<'\n';
	return 0;
}