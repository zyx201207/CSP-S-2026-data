#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		printf("1");
		bool f=1;
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i])
			{
				f=0;
				break;
			}
		}
		if(f==1)
		{
			printf("1");
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')))
			{
				printf("00");
			}
			else
			{
				printf("1");
				char ss=s1[2],sss=s2[2];
				if((ss=='A'&&sss=='B')||(ss=='B'&&sss=='A')||(ss=='B'&&sss=='C')||(ss=='C'&&sss=='B')||(ss=='D'&&sss=='F')||(ss=='F'&&sss=='D'))
				{
					printf("1");
				}
				else printf("0");
			}
		}
		else printf("000");
	}
	else printf("0000");
	
	
	return 0;
}
