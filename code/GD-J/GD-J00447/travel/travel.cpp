#include<bits/stdc++.h>
using namespace std;
char s1[5];
char s2[5];
int s3[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
		cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1==c2)
	{
		s3[0]=1;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			cout<<s3[i];
		}
		return 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		s3[1]=1;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			cout<<s3[i];
		}
		return 0;
	}
	bool f=1;
	if((s1[3]=='C'&&s2[3]=='D')||(s1[3]=='D'&&s2[3]=='C'))
	{
		s3[2]=0;
		f=0;
	}
	else s3[2]=1;
	if((int)s1[3]-(int)s2[3]!=1&&(int)s2[3]-(int)s1[3]!=1)
	{
		s3[3]=0;
	}
	else s3[3]=1;
	if(f==0)
	{
		s3[2]=0;
		s3[3]=0;
	}
	for(int i=0;i<4;i++)
	{
		cout<<s3[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
