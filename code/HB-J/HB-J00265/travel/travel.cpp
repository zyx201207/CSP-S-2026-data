#include <bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
bool flag1=0,flag2=0,flag3=0,flag4=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)flag1=1;
	if(flag1==1&&s1[0]==s2[0]&&s1[1]==s2[1])flag2=1;
	if(flag2==1&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		flag3=1;
	if(flag3==1&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		flag4=1;
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
