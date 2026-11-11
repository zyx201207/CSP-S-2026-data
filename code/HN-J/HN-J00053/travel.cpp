#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,g,b,c,d,e,f;
	string c1,s1,c2,s2,a;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	  a[0]='1';
	else
	   a[0]='0';
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&a[0]==1)
	  a[1]='1';
	else
	   a[1]='0';
	if(a[1]==1&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='B'||s2[2]=='C'||s2[2]=='A'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
	   a[2]='1';
	else
	   a[2]='0';  
	f=(s1[2]-'0')-(s2[2]-'0');
	if(a[1]==1&&a[2]==1&&a[0]==1)
	 a[3]='1';
	else
	   a[3]='0';
	if((f==1||f==-1)&&a[2]==1)
	 a[3]='1';
	else
	   a[3]='0';
for(i=0;i<4;i++)
   cout<<a[i];

	fclose(stdin);
	fclose(stdout);
	return 0;
}
