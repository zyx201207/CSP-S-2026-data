#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	int cx=0,p=0,pc=0,xl=0; 
	//是否同一车厢，排，排和侧，相邻 
	cx=(c1==c2);
	if(cx)
		p=((s1[0]+s1[1])==(s2[0]+s2[1]));
	if(p)
	{
		if((s1[2]=='A' or s1[2]=='B' or s1[2]=='C') and 
			(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'))
			pc=1;
		else if((s1[2]=='E' or s1[2]=='F') and 
			(s2[2]=='E' or s2[2]=='F'))
			pc=1;
	}
	if(pc)
	{
		if(abs(s1[2]-s2[2])==1)
			xl=1;
	}
	cout<<cx<<p<<pc<<xl;
	return 0;
}
