#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	int ans[4]={1,0,0,0};
	getline(cin,c1);
	getline(cin,s1);
	getline(cin,c2);
	getline(cin,s2);
	if(s1[0]==s2[0]&&s1[1]==s2[1])ans[1]=1;
	else ans[1]=0;
	if(((('s1[2]'!='D')&&('s1[2]'!='F'))&&(('s2[2]'!='D')&&('s2[2]'!='F')))||((('s1[2]'=='D')||('s1[2]'=='F'))&&(('s2[2]'=='D')||('s2[2]'=='F'))))ans[2]=1;
	else ans[2]=0;
	if(('s1[2]'=='A'&&'s2[2]'=='B')||('s2[2]'=='A'&&'s1[2]'=='B')||('s1[2]'=='B'&&'s2[2]'=='C')||('s2[2]'=='B'&&'s1[2]'=='C')||('s1[2]'=='D'&&'s2[2]'=='F')||('s2[2]'=='D'&&'s1[2]'=='F'))ans[3]=1;
	else ans[3]=0;
	for(int i=0;i<=3;i++)
	cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
