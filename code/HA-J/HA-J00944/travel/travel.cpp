#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a[10]={0,0,0,0};
	int n=s1[2];
	int m=s2[2];
	if(c1==c2)
	{
		a[0]=1;
	}
	if(a[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		a[1]=1;
	}
	if(a[1]==1&&'n'>='A'&&'n'<='C'&&'m'>='A'&&'m'<='C')
	{
		a[2]=1;
	}
	else if(a[1]==1&&'n'<='F'&&'n'>='D'&&'m'>='D'&&'m'<='F')
	{
		a[2]=1;
	}
	else
	{
		a[2]=0;
	}
	if(a[2]==1&&'n'+1=='m'||'n'-1=='m')
	{
		a[3]=1;
	}
	for(int i=0;i<=3;i++)
	{
		cout<<a[i];
	}
	return 0;
}
