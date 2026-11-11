#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	char ccs1=s1[0]+s1[1];
	char ccs2=s2[0]+s2[1];
	if(c1==c2&&ccs1==ccs2)
		cout<<1;
	else cout<<0;
	if(c1==c2&&ccs1==ccs2)
	{
		if((s2[2]=='D'&&s1[2]=='F')||(s2[2]=='F'&&s1[2]=='D'))cout<<1;
		else
		{
			bool vis=0;
			if(s2[2]=='D'||s1[2]=='F'||s2[2]=='F'||s1[2]=='D')cout<<0;
			else cout<<1;
		}
	}
	else cout<<0;
	if(s1[2]>s2[2])swap(s1[2],s2[2]);
	if(c1==c2&&ccs1==ccs2)
	{
		if((s1[2]=='A'&&s2[2]=='B')
			||(s1[2]=='B'&&s2[2]=='C')
			||(s1[2]=='D'&&s2[2]=='F'))
			cout<<1;
		else cout<<0;
	}
	else cout<<0;
}
