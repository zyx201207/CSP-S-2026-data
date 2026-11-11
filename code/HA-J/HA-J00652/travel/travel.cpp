#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string s1,s2,s3,s4,ss2,ss4;
char m2,m4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) printf("1");
	else 
	{
		printf("0000");return 0;
	}
	for(int i=0;i<s2.size()-1;i++)
	{
		ss2+=s2[i];
		ss4+=s4[i];
	}
	m2=s2[s2.size()-1];
	m4=s4[s4.size()-1];
	if(ss2==ss4) printf("1");
	else 
	{
	printf("000");return 0;	
	}
	if(((m2=='A'||m2=='B'||m2=='C')&&(m4=='A'||m4=='B'||m4=='C'))||((m2=='F'||m2=='D')&&(m4=='D'||m4=='F'))) printf("1");
	else 
	{
	printf("00");return 0;	
	}
	if(abs((m2-'A')-(m4-'A'))==1) printf("1");
	else printf("0");
	return 0;
}
