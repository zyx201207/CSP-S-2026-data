#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int i1,i2;
	i1=int(s1[2]);
	i2=int(s2[2]);
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else if(!(s1[0]==s2[0]&&s1[1]==s2[1]))
	{
		cout<<"1000";
	}
	else if(!(65<=i1<=67&&65<=i2<=67||68<=i1<=70&&68<=i2<=70))
	{
		cout<<"1100";
	}
	else if(!(i1==65&&i2==66||i1==66&&(i2==65||i2==67)||i1==67&&i2==66||i1==68&&i2==70||i1==70||i2==68))
	{
		cout<<"1110";
	}
	else cout<<"1111";
	return 0;
}