#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	s2=' '+s2;
	s4=' '+s4;
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	if(s2[1]!=s4[1]||s2[2]!=s4[2])
	{
		cout<<"1000";
		return 0;
	}
	if(s2[3]<='C'&&s4[3]>='D'||s2[3]>='D'&&s4[3]<='C')
	{
		cout<<"1100";
		return 0;
	}
	if(s2[3]>='D'&&s4[3]>='D')
	{
		cout<<"1111";
		return 0;
	}
	if(s2[3]=='A'&&s4[3]=='C'||s2[3]=='C'&&s4[3]=='A')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";





	return 0;
}

