#include<bits/stdc++.h>
using namespace std;
char c1[10],c2[10],s1[10],s2[10];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	int x1=(c1[0]-'0')*10+c1[1]-'0';
	int x2=(c2[0]-'0')*10+c2[1]-'0';
	int f=0;
	if(x1==x2)
	{
		printf("1");
	}
	else
	{
		f=1;
		printf("0000");
	}
	int h1=(s1[0]-'0')*10+s1[1]-'0';
	int h2=(s2[0]-'0')*10+s2[1]-'0';
	if(h1==h2 && f==0)
	{
		printf("1");
	}
	else if(f==0)
	{
		printf("000");
		f=1;
	}
	if(f==0 && ('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C' || 'D'<=s1[2] && s1[2]<='F' && 'D'<=s2[2] && s2[2]<='F'))
	{
		printf("1");
	}
	else if(f==0)
	{
		printf("00");
		f=1;
	}
	if(f==0 && (s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A' || s1[2]=='B' && s2[2]=='C' || s1[2]=='C' && s2[2]=='B' || s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D'))
	{
		printf("1");
	}
	else if(f==0)
	{
		printf("0");
	}
	return 0;
}
