#include<bits/stdc++.h>
using namespace std;
string s3,s4,s1,s2;
string a,b;
bool o[4];
void ch()
{
	//³µÏá
	if(s3==s4)
	{
		o[0]=1;
	}else return;

	//ÅÅ
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	if(a==b)
	{
		o[1]=1;
	}else return;

	//×ùÎ»
	if(s1[2]>='D' && s2[2]>='D')
	{
		o[2]=1;
		o[3]=1;
		return;
	}else if(s1[2]<='C' && s2[2]<='C')
	{
		o[2]=1;
	}else return;

	if(abs(s1[2]-s2[2])<=1)
	{
		o[3]=1;

	}else return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>s3>>s1>>s4>>s2;
	ch();
	for(int i=0;i<4;i++)
	{
		if(o[i]) cout<<"1";
		else cout<<"0";
	}

	fclose(stdin);
	fclose(stdout);
}
