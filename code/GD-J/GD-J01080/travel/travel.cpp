#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int pd=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
	if(c1[i]!=c2[i])
	pd=0;
	if(pd==0)
	{
		cout<<"0000";
		return 0;
	}
	else
	cout<<1;
	pd=1;
	for(int i=0;i<s1.size()-1;i++)
	if(s1[i]!=s2[i])
	pd=0;
	cout<<pd;
	if(pd==1)
	{
		pd=0;
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'))
		pd=1;
	}
	cout<<pd;
	if(pd==1)
	{
		pd=0;
		if((s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'))
		pd=1;
			
	}
		cout<<pd;
		fclose(stdin);
		fclose(stdout);
	return 0;
} //Trick||Treat!
