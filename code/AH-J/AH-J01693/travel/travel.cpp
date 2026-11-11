#include <bits/stdc++.h>
using namespace std;
bool p[5];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) 
	{
		for(int i=1;i<=4;i++) cout<<p[i];
		return 0;
	}
	p[1]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) 
	{
		p[2]=1;
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') p[3]=1;
		else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') p[3]=1;
		if(p[3]==1)
		{
			if(abs(s1[2]-s2[2])==1) p[4]=1;
		}
	}
	for(int i=1;i<=4;i++) cout<<p[i];
	return 0;
} 
