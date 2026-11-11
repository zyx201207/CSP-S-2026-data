#include<bits/stdc++.h>
using namespace std;
//const int N=;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	int a=(s1[0]-'0')*10+s1[1]-'0';
	int b=(s2[0]-'0')*10+s2[1]-'0';
	if(a!=b)
	{
		cout<<"1000";
		return 0;
	}
	a=s1[2]-'A';
	b=s2[2]-'A';
	int flag=0,flag1=0;
	if(a==0||a==2||a==1)flag=1;
	if(b==0||b==2||b==1)flag1=1;
	if(flag!=flag1)
	{
		cout<<"1100";
		return 0;
	}
	if(abs(a-b)!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
   return 0;
}
//Trick||Treat!
//172.16.12.5
