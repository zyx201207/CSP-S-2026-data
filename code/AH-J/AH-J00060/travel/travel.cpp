#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	string res="0000";
	if(c1==c2)
	{
		res[0]='1';
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			res[1]='1';
			if((s1[2]<'D')^(s2[2]<'D')==0)
			{
				res[2]='1';
				if(abs(s1[2]-s2[2])==1)
					res[3]='1';
			} 
		}
	}
	cout<<res; 
	return 0;
} 
