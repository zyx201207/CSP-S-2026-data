#include<bits/stdc++.h>
using namespace std;
string s1,n,s2,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>n>>s2>>m;
	if(s1==s2)//≥µœ· 
	{
		printf("1");
		if(n[0]==m[0]&&n[1]==m[1])//≈≈ 
		{
			printf("1");
			if(('A'<=n[2]&&n[2]<='C')&&('A'<=m[2]&&m[2]<='C'))//≤‡ 
			{
				printf("1");
			}
			else if((n[2]=='D'||n[2]=='F')&&(m[2]=='D'||m[2]=='F'))//≤‡ 
			{
				printf("1");
			}
			else printf("0");
		}
		else printf("00");
	}
	else printf("000");
	if(n[0]==m[0]&&n[1]==m[1])//œ‡¡⁄ 
	{
		if(('A'<=n[2]&&n[2]<='C')&&('A'<=m[2]&&m[2]<='C'))
		{
			if(abs(n[2]-m[2])==1)
			{
				printf("1");
			}
			else printf("0");
		}
		else if((n[2]=='D'||n[2]=='F')&&(m[2]=='D'||m[2]=='F'))
		{
			if(abs(n[2]-m[2])==2)
			{
				printf("1");
			}
			else printf("0");
		}
		else printf("0");
	}
	else printf("0");
	return 0;
}
