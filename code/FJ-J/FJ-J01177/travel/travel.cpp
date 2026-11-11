#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;//在同车 
	if(s1[0]!=s2[0]/*排号十位*/||s1[1]!=s2[1]/*排号个位*/)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;//在同排 
	if(
	   !( 
			(s1[2]<='C'&&s2[2]<='C')/*ABC*/ || (s1[2]>='D'&&s2[2]>='D')/*DF*/ 
		) 
	  )
	{
		cout<<"00";
		return 0;
	}
	cout<<1;//在同侧 
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
	{
		cout<<0;
		return 0;	
	}
	//cout<<s1[2]<<s2[2];
	cout<<1;
	return 0;
}
