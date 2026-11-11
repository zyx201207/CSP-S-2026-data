#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[4],c2[3],s2[4];
	scanf("%s %s %s %s",c1,s1,c2,s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1])
    {
    	printf("%c",'1');
	}
	else
	{
		printf("%c",'0');
		printf("%c",'0');
		printf("%c",'0');
		printf("%c\n",'0');
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
	    printf("%c",'1');
	}
	else
	{
		printf("%c",'0');
		printf("%c",'0');
		printf("%c\n",'0');
		return 0;
	} 
	if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C'))
    {
    	printf("%c",'0');
	    printf("%c\n",'0');
	    return 0;
	}
	else
	{
		printf("%c",'1');
	} 
	if(abs(int(s1[2])-int(s2[2]))==1)
    {
	    printf("%c\n",'1');
	}
	else
	{
		printf("%c\n",'0');
		return 0;
	} 
	return 0;
}
