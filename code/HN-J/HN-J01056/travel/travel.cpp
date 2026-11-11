#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >>s1>>s2>>s3>>s4;
	int a1=0;
	int a2=0;
	int a3=0;
	int a4=0;
	if(s1==s3) a1=1;
	
	if(a1==1&&s2[0]==s4[0]&&s2[1]==s4[1]) a2=1;
	
	if(a1==1&&a2==1&&s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C')) a3=1;
	if(a1==1&&a2==1&&s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C')) a3=1;
	if(a1==1&&a2==1&&s2[2]=='C'&&(s4[2]=='A'||s4[2]=='B')) a3=1;
	if(a1==1&&a2==1&&s2[2]=='F'&&s4[2]=='D') a3=1;
	if(a1==1&&a2==1&&s2[2]=='D'&&s4[2]=='F') a3=1;
	
	if(a1==1&&a2==1&&a3==1&&s2[2]=='A'&&s4[2]=='B') a4=1;
	if(a1==1&&a2==1&&a3==1&&s2[2]=='B'&&(s4[2]=='C'||s4[2]=='A')) a4=1;
	if(a1==1&&a2==1&&a3==1&&s2[2]=='C'&&s4[2]=='B') a4=1;
	if(a1==1&&a2==1&&a3==1&&s2[2]=='D'&&s4[2]=='F') a4=1;
	if(a1==1&&a2==1&&a3==1&&s2[2]=='F'&&s4[2]=='D') a4=1;
	
	cout <<a1<<a2<<a3<<a4;
	return 0;
}
