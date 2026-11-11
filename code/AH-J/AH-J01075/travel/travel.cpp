#include<bits/stdc++.h>
using namespace std;
string s1,t1,s2,t2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>t1>>s2>>t2;
	if(s1!=s2)cout<<"0000";
	else
	{
		cout<<1;
		if(t1[0]==t2[0] and t1[1]==t2[1])
		{
			cout<<1;
			if(t1[2]=='A' and t2[2]=='B' or t1[2]=='B' and t2[2]=='A')cout<<11;
			else if(t1[2]=='B' and t2[2]=='C' or t1[2]=='C' and t2[2]=='B')cout<<11;
			else if(t1[2]=='D' and t2[2]=='E' or t1[2]=='E' and t2[2]=='D')cout<<11;
			else if(t1[2]=='A' and t2[2]=='C' or t1[2]=='C' and t2[2]=='A')cout<<10;
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}
