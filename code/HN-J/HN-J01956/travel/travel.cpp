#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[3],c2[3],s2[3];
	int a=0,b=0;
	scanf("%s%s%s%s",c1,s1,c2,s2);
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			a=0;
			break;
		}
		a=1;
	}
	if(a)
		printf("1");
	else
		printf("0");
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			b=0;
			break;
		}
		b=1;
	}
	if(a&&b)
		printf("1");
	else
		printf("0");
	if(a&&b&&((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D')))
	{

		printf("1");
}	else
	printf("0");
	if((s1[2]=='C'&&s2[2]=='D'||(s1[2]=='D'&&s2[2]=='C')))
	{
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int m_s1=10*s1[0]+s1[1],m_s2=10*s2[0]+s2[1];
	if(((m_s1==m_s2-1||m_s1==m_s2+1)&&s1[2]==s2[2])||(s1[2]==s2[2]-1||s1[2]==s2[2]+1)&&m_s1==m_s2&&(!(s1[2]=='D'&&s2[2]=='C')||!(s2[2]=='D'&&s1[2]=='C')))  
		printf("1");
	else
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
