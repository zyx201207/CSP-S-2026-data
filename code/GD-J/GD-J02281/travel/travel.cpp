#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int s[4]={};
	if(a==c)
	{
	s[0]=1;
	if(b[0]==d[0]&&b[1]==d[1])
	{
	s[1]=1;
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))
	{
	s[2]=1;
	if(b[2]+1==d[2]||d[2]+1==b[2])
	{
	s[3]=1;
	}
	}
	}
	}
	for(int i=0;i<4;i++)
	{
	cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
