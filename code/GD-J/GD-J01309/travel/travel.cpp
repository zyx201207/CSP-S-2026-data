#include<bits/stdc++.h>
using namespace std;
char s1[150],s2[150],t1[150],t2[150];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",s1+1,s2+1,t1+1,t2+1);
	if(s2[3]=='F')s2[3]--;
	if(t2[3]=='F')t2[3]--;
	if(s1[1]==t1[1]&&s1[2]==t1[2])
	{
		putchar('1');
		if(s2[1]==t2[1]&&s2[2]==t2[2])
		{
			putchar('1');
			if((s2[3]<='C')^(t2[3]<='C'))puts("00");
			else
			{
				putchar('1');
				if(abs(s2[3]-t2[3])==1)puts("1");
				else puts("0");
			}
		}
		else puts("000");
	}
	else puts("0000");
	return 0;
}
