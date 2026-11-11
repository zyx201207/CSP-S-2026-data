#include<bits/stdc++.h>
using namespace std;
int c1=0,c2=0,f1=0,f2=0,f3=0,f4=0;
char s1[10]={'\0'},s2[10]={'\0'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)f1=1;
	else
	{
		cout<<f1<<f2<<f3<<f4;return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])f2=1;
	else
	{
		cout<<f1<<f2<<f3<<f4;return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
	{
		f3=1;
	}
	else
	{
		cout<<f1<<f2<<f3<<f4;return 0;
	}
	if(abs(s1[2]-s2[2])==1)f4=1;
	cout<<f1<<f2<<f3<<f4;
	
	return 0;
}
//要是这题不是满分我把准考证吃了 
