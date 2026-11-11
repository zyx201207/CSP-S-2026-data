#include<bits/stdc++.h>
using namespace std;
char c[5],s[5],cc[5],ss[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf(" %s %s %s %s",c,s,cc,ss);
	if(strcmp(c,cc)==0) 
	{
	    printf("1");
	    if(s[0]==ss[0] && s[1]==ss[1]) 
	    {
	    	printf("1");
	    	if(s[2]=='D'||s[2]=='F')
	    	{
	    		if(ss[2]=='F'||ss[2]=='D')
	    		    printf("11");
	    		else printf("00");
			}
			else
			{
				if(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')
			    {
				    printf("1");
				    if(ss[2]=='A' && s[2]=='C') printf("0");
				    else printf("1");
				}
				else
				    printf("00");
			}
		}
		else printf("000");
	}
	else printf("0000");
	
	fclose(stdin);fclose(stdout);
	return 0;
} 
