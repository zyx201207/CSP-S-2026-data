#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	string sc2,ss2;//sc2 ss2 to mark c2[0,1],s2[0,1]
	if(c2[2]=='F') c2[2]='E';
	if(s2[2]=='F') s2[2]='E';
	for(int i=0;i<=1;i++)
	{
		sc2+=c2[i];
		ss2+=s2[i];
	}
	if(c1!=s1)
	{
		cout<<"0000";
		return 0;
	}
	else if(sc2!=ss2)
	{
		cout<<"1000";
		return 0;
	}
	else if((c2[2]>='A' && c2[2]<='C') && s2[2]>='D')
	{
		cout<<"1100";
		return 0;
	} 
	else if((c2[2]=='D' || c2[2]=='E') && s2[2]<='C')
	{
		cout<<"1100";
		return 0;
	}
	else if((c2[2]+1==s2[2] && c2[2]!='C') || (c2[2]-1==s2[2] && c2[2]!='D'))
	{
		cout<<"1111";
		return 0;
	}
	else 
	{
		cout<<"1110";
		return 0;
	}
}
