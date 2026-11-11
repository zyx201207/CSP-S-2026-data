#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	long long i;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0] and c1[1]==c2[1])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((c1[2]>='A' and c1[2]<='C' and c2[2]>='A' and c2[2]<='C') or (c1[2]>='D' and c1[2]<='F' and c2[2]>='D' and c2[2]<='F'))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(c1[2]-c2[2])==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}