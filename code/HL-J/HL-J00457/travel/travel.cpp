#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int c=s1[0]-'0';
	int d=s2[0]-'0';
   int a=s1[1]-'0';
   int b=s2[1]-'0';
	
	if(a==b&&c==d)
	{
		cout<<"1";	
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char a1=s1[2],a2=s2[2];
	if(((a1=='A'||a1=='B'||a1=='C')&&(a2=='A'||a2=='B'||a2=='C'))||( (a1=='D'||a1=='F')&&(a2=='D'||a2=='F') ))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((a1<a2&&a1==a2-1)||(a1>a2&&a1==a2+1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
