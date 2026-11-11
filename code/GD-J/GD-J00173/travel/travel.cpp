#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	string s3,s4;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		printf("0000");
		return 0;
	}
	if(s4[0]!=s2[0]||s4[1]!=s2[1])	printf("1000");
	
	else if(s4[2]<='C'&&s2[2]>'c'||s4[2]>='D'&&s2[2]<='C') printf("1100");
	 else
	 {
	 	if(char(s4[2]+1)==s2[2]||char(s4[2]-1)==s2[2]) printf("1111");
	 	else if(s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D')
		  printf("1111");
	 	else 
		 printf("1110");
	 }
	
	return 0; 
}
